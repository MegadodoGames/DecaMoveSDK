// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "Delegates/Delegate.h"
#include "include/move.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Math/Vector.h"
#include "Math/Quat.h"
#include <atomic>
#include <queue>
#include "DecaMoveSDK.generated.h"


class FDecaMoveSDKModule : public IModuleInterface
{
private:
	static void* DecaMoveLibraryHandle;

	static void SetupMove();
	static void CleanUpMove();
	static deca_move move;

	struct MoveContext
	{
		// Since these are updated by background threads they all need to be thread safe
		std::atomic<deca_move_state> state = kDecaMoveStateClosed;
		std::atomic<bool> isSleeping = true;
		std::atomic<FVector> position = FVector(0,0,0);
		std::atomic<FQuat> rotation = FQuat(0,0,0,1);
		std::atomic<float> yawOffset = 0;
		std::atomic<bool> singleClicked = false;
		std::atomic<bool> doubleClicked = false;
		std::atomic<bool> tripleClicked = false;
	};

	static MoveContext _moveContext;

	static FQuat DecaToUnreal(const deca_move_quaternion& value);


public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	static void LinkDll();
	static void ReleaseDll();

	static FRotator GetMoveRotation();
	static FQuat GetMoveRawRotation();
	static FVector GetMovePosition();
	static float GetMoveYawOffset();
	static deca_move_state GetMoveState();
	static bool IsMoveSleeping();

	static void CalibrateMove(float forwardX, float forwardY);
	static void SendHaptic();

	static bool GetIfMoveSingleClicked();
	static bool GetIfMoveDoubleClicked();
	static bool GetIfMoveTripleClicked();
};

UCLASS()
class UDecaMoveLoadSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem
private:
	// All my variables
};

