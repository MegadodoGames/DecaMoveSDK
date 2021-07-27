// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "Delegates/Delegate.h"
#include "include/move.h"
#include "Math/Vector.h"
#include "Math/Quat.h"
#include <mutex>   
#include <queue>



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
		deca_move_state state;
		bool isSleeping;
		FVector position;
		FQuat rotation;
		float yawOffset;
		bool singleClicked;
		bool doubleClicked;
		bool tripleClicked;
		std::mutex lock;
		MoveContext();
	};

	static MoveContext _moveContext;

	static FQuat DecaToUnreal(const deca_move_quaternion& value);


public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	static void StartSDK();
	static void ReleaseSDK();

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



