// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestTopDownCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"

ATestTopDownCharacter::ATestTopDownCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create DecaMove device
	DecaMove = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DecaMove"));
	DecaMove->SetupAttachment(RootComponent);
	UStaticMesh* decaMoveMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/TopDownCPP/DecaMoveGameModel/Decamove_game_model.Decamove_game_model'")).Object;
	DecaMove->SetStaticMesh(decaMoveMesh);
	DecaMove->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	// Create testing cube
	TestingCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TestingCube"));
	TestingCube->SetupAttachment(RootComponent);
	UStaticMesh* testingCubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/TopDownCPP/TestingCube/cube.cube'")).Object;
	TestingCube->SetStaticMesh(testingCubeMesh);
	TestingCube->SetRelativeLocation(FVector(-100.0f, -100.0f, 100.0f));

	_decaMove = nullptr;
	_quaternion = FQuat();

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

ATestTopDownCharacter::~ATestTopDownCharacter() {
	if (_decaMove) {
		decaMoveRelease(_decaMove);
	}
}

// Called when the game starts
void ATestTopDownCharacter::BeginPlay() {
	Super::BeginPlay();

	deca_move_callbacks decaMoveCallbacks = {};
	decaMoveCallbacks.user_data = this;
	decaMoveCallbacks.feedback_cb = [](deca_move_feedback feedback, void* userData) {
		ATestTopDownCharacter* self = (ATestTopDownCharacter*)userData;
		UE_LOG(LogActor, Error, TEXT("Feedback: %d"), int(feedback));
	};
	decaMoveCallbacks.orientation_update_cb = [](deca_move_quaternion quaternion, deca_move_accuracy accuracy, float yawDrift, void* userData) {
		ATestTopDownCharacter* self = (ATestTopDownCharacter*)userData;
		auto q = FRotator(0, FMath::RadiansToDegrees(yawDrift), 0).Quaternion() * decaMoveToUE(quaternion);
		std::lock_guard<std::mutex> lock(self->_mutex);
		self->_quaternion = q;
	};
    deca_move_env_desc envDesc = {};
    envDesc.flags = kDecaMoveEnvComLib;
	envDesc.log_callback = [](deca_move_env_log_level logLevel, const char* message, void* userData) {
		FString s(message);
		UE_LOG(LogActor, Error, TEXT("%s"), *s);
	};
	deca_move_status status = decaMoveInit(envDesc, decaMoveCallbacks, &_decaMove);
	UE_LOG(LogActor, Error, TEXT("decaMoveInit: %d"), int(status));
}

void ATestTopDownCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (CursorToWorld != nullptr)
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UWorld* World = GetWorld())
			{
				FHitResult HitResult;
				FCollisionQueryParams Params(NAME_None, FCollisionQueryParams::GetUnknownStatId());
				FVector StartLocation = TopDownCameraComponent->GetComponentLocation();
				FVector EndLocation = TopDownCameraComponent->GetComponentRotation().Vector() * 2000.0f;
				Params.AddIgnoredActor(this);
				World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
				FQuat SurfaceRotation = HitResult.ImpactNormal.ToOrientationRotator().Quaternion();
				CursorToWorld->SetWorldLocationAndRotation(HitResult.Location, SurfaceRotation);
			}
		}
		else if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FHitResult TraceHitResult;
			PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			CursorToWorld->SetWorldLocation(TraceHitResult.Location);
			CursorToWorld->SetWorldRotation(CursorR);
		}
	}

	std::lock_guard<std::mutex> lock(_mutex);

	{
		FRotator modelRotation(-90, 0, 0);
		DecaMove->SetRelativeRotation(_quaternion * modelRotation.Quaternion());
	}

	{
		FVector modelScale(1, -1, 1);
		FRotator modelRotation(0, 90, -90);

		auto rotation = _quaternion * modelRotation.Quaternion();
		rotation.Normalize();

		TestingCube->SetRelativeRotation(rotation);
		TestingCube->SetRelativeScale3D(modelScale);
	}
}

void ATestTopDownCharacter::Calibrate() {
	decaMoveCalibrate(_decaMove, 0.0f, 1.0f);
}
