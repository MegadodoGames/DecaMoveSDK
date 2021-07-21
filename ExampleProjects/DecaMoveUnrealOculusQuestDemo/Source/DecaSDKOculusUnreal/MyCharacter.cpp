// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "deca/unreal.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DecaMove = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DecaMove"));
	DecaMove->SetupAttachment(RootComponent);
	UStaticMesh* decaMoveMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/UEDecaSDK/DecaMoveGameModel/Decamove_game_model.Decamove_game_model'")).Object;
	DecaMove->SetStaticMesh(decaMoveMesh);
	DecaMove->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	_quaternion = FQuat();
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogActor, Error, TEXT("MyCharacter::BeginPlay"));

	deca_move_callbacks decaMoveCallbacks = {};
	decaMoveCallbacks.user_data = this;
	decaMoveCallbacks.feedback_cb = [](deca_move_feedback feedback, void* userData) {
		AMyCharacter* self = (AMyCharacter*)userData;
		UE_LOG(LogActor, Error, TEXT("Feedback: %d"), int(feedback));
	};
	decaMoveCallbacks.orientation_update_cb = [](deca_move_quaternion quaternion, deca_move_accuracy accuracy, float yawDrift, void* userData) {
		AMyCharacter* self = (AMyCharacter*)userData;
		auto q = FRotator(0, FMath::RadiansToDegrees(yawDrift), 0).Quaternion() * decaMoveToUE(quaternion);
		std::lock_guard<std::mutex> lock(self->_mutex);
		self->_quaternion = q;
	};
	deca_move_env_desc decaMoveEnvDesc = {};
	decaMoveEnvDesc.flags = kDecaMoveEnvComLib;
	decaMoveEnvDesc.log_callback = [](deca_move_env_log_level logLevel, const char* message, void* userData) {
		FString s(message);
		UE_LOG(LogActor, Error, TEXT("%s"), *s);
	};
	deca_move_status status = decaMoveInit(decaMoveEnvDesc, decaMoveCallbacks, &_decaMove);
	if (status != kDecaMoveStatusSuccess) {
		UE_LOG(LogActor, Error, TEXT("Failed to setup deca move: %d"), int(status));
	} else {
		UE_LOG(LogActor, Error, TEXT("Deca move has been set up"));
	}
}

void AMyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	decaMoveRelease(_decaMove);
	_decaMove = nullptr;
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_decaMove) {
		static int prevStep = -1;
		static float elapsedTime = 0.0f;
		elapsedTime += DeltaTime;

		const float kStepDuration = 2.0f;
		int currStep = int(elapsedTime / kStepDuration);
		if (prevStep != currStep) {
			prevStep = currStep;
			decaMoveSendHaptic(_decaMove);
		}

		std::lock_guard<std::mutex> lock(_mutex);

		{
			FRotator modelRotation(-90, 0, 0);
			DecaMove->SetRelativeRotation(_quaternion * modelRotation.Quaternion());
		}
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

