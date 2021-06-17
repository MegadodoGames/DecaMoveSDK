// Copyright Epic Games, Inc. All Rights Reserved.

#include "DecaMoveSDK.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Math/UnrealMathUtility.h"
#include "Interfaces/IPluginManager.h"
#include "DecaMoveSDKLibrary/include/move.h"

#define LOCTEXT_NAMESPACE "FDecaMoveSDKModule"

void FDecaMoveSDKModule::StartupModule()
{
}

void FDecaMoveSDKModule::LinkDll()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if PLATFORM_WINDOWS

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("DecaMoveSDK")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/Win64/deca_sdk.dll"));

    UE_LOG(LogTemp, Display, TEXT("Loading DecaMoveSDK"));
	DecaMoveLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
	if (DecaMoveLibraryHandle)
	{
		
        try
        {
            SetupMove();
        }
        catch (const std::exception& e)
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to intialize deca move library, exception was thrown "), *e.what());
        }
        
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load deca move library"));
	}
#endif // PLATFORM_WINDOWS
}


void FDecaMoveSDKModule::ShutdownModule()
{
}

void FDecaMoveSDKModule::ReleaseDll()
{
#if PLATFORM_WINDOWS
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
    UE_LOG(LogTemp, Display, TEXT("Unloading DecaMoveSDK"));

    // Clean up the move
    CleanUpMove();

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(DecaMoveLibraryHandle);
	DecaMoveLibraryHandle = nullptr;
#endif // PLATFORM_WINDOWS
}

FDecaMoveSDKModule::MoveContext FDecaMoveSDKModule::_moveContext;
void* FDecaMoveSDKModule::DecaMoveLibraryHandle = nullptr;
deca_move FDecaMoveSDKModule::move;

void FDecaMoveSDKModule::SetupMove()
{

    deca_move_callbacks callbacks = {};
    callbacks.feedback_cb = [](deca_move_feedback feedback, void* userData)
    {
        MoveContext* ctx = ((MoveContext*)userData);
        UE_LOG(LogTemp, Log, TEXT("Feedback: %d\n"), int(feedback));
        switch (feedback)
        {
            case kDecaMoveFeedbackEnteringSleep:
                ctx->isSleeping = true;
                break;
            case kDecaMoveFeedbackLeavingSleep:
                ctx->isSleeping = false;
                break;
            case kDecaMoveFeedbackShuttingDown:
                break;
            case kDecaMoveFeedbackSingleClick:
                ctx->singleClicked = true;
                break;
            case kDecaMoveFeedbackDoubleClick:
                ctx->doubleClicked = true;
                break;
            case kDecaMoveFeedbackTripleClick:
                ctx->tripleClicked = true;
                break;
        }

    };
    callbacks.battery_update_cb = [](float charge, void* userData)
    {
        //UE_LOG(LogTemp, Log, TEXT("Battery: %g%%\n"), charge);
    };
    callbacks.orientation_update_cb = [](deca_move_quaternion quat, deca_move_accuracy accuracy, float yawCalibration, void* userData)
    {
        ((MoveContext*)userData)->rotation = DecaToUnreal(quat);
        ((MoveContext*)userData)->yawOffset = yawCalibration;
        //UE_LOG(LogTemp, Log, TEXT("Orientation: %.2f %.2f %.2f %.2f yaw=%.2f [%d]\n"), quat.x, quat.y, quat.z, quat.w, yawCalibration, int(accuracy));
    };
    callbacks.position_update_cb = [](float position_x, float position_y, float position_z, void* userData)
    {
        ((MoveContext*)userData)->position = FVector(position_x, position_y, position_z);
        //UE_LOG(LogTemp, Log, TEXT("Position: %.2f %.2f %.2f\n"), position_x, position_y, position_z);
    };
    callbacks.state_update_cb = [](deca_move_state state, void* userData)
    {
        ((MoveContext*)userData)->state = state;
        //UE_LOG(LogTemp, Log, TEXT("State: %d\n"), state);
    };
    callbacks.imu_calibration_request_cb = [](void* userData)
    {
        UE_LOG(LogTemp, Warning, TEXT("IMU calibration has been requested\n"));
    };
    callbacks.user_data = &_moveContext;

    deca_move_env_desc envDesc = {};
    envDesc.flags = kDecaMoveEnvComLib;
    envDesc.log_callback = [](deca_move_env_log_level logLevel, const char* message, void* userData)
    {
        FString s(message);
        switch (logLevel)
        {
            case kDecaMoveEnvLogLevelTrace:
                UE_LOG(LogTemp, Verbose, TEXT("%s"), *s);
                break;
            case kDecaMoveEnvLogLevelDebug:
                UE_LOG(LogTemp, Log, TEXT("%s"), *s);
                break;
            case kDecaMoveEnvLogLevelInfo:
                UE_LOG(LogTemp, Log, TEXT("%s"), *s);
                break;
            case kDecaMoveEnvLogLevelWarn:
                UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
                break;
            case kDecaMoveEnvLogLevelErr:
                UE_LOG(LogTemp, Error, TEXT("%s"), *s);
                break;
            case kDecaMoveEnvLogLevelCritical:
                UE_LOG(LogTemp, Error, TEXT("%s"), *s);
                break;
            default:
                UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
                break;
        }
        
    };
    

    move = nullptr;
    auto status = decaMoveInit(envDesc, callbacks, &move);
    if (status == kDecaMoveStatusSuccess)
    {
        UE_LOG(LogTemp, Log, TEXT("Deca Move sucessfully set up"));
    }
}
FQuat FDecaMoveSDKModule::DecaToUnreal(const deca_move_quaternion& value)
{
    FQuat o;
    o.X = -value.x;
    o.Y = value.y;
    o.Z = -value.z;
    o.W = value.w;
    const FQuat localOffset = FRotator(90, 180, 0).Quaternion();
    const FQuat globalOffset = FRotator(0, -90, 0).Quaternion();
    o = globalOffset * o * localOffset;
    return o;
}
void FDecaMoveSDKModule::CleanUpMove()
{
    decaMoveRelease(move);
}


FRotator FDecaMoveSDKModule::GetMoveRotation()
{
    FRotator o = FRotator(FQuat(FVector(0, 0, 1), _moveContext.yawOffset) * _moveContext.rotation);
    return o;
};

float FDecaMoveSDKModule::GetMoveYawOffset()
{
    return _moveContext.yawOffset;
}

FQuat FDecaMoveSDKModule::GetMoveRawRotation()
{
    return _moveContext.rotation;
};

FVector FDecaMoveSDKModule::GetMovePosition()
{
    return _moveContext.position;
}

deca_move_state FDecaMoveSDKModule::GetMoveState()
{
    return _moveContext.state;
}

bool FDecaMoveSDKModule::IsMoveSleeping()
{
    return _moveContext.isSleeping;
}

void FDecaMoveSDKModule::CalibrateMove(float forwardX, float forwardY)
{
    decaMoveCalibrate(move, forwardX, -forwardY);
}

void FDecaMoveSDKModule::SendHaptic()
{
    decaMoveSendHaptic(move);
}

bool FDecaMoveSDKModule::GetIfMoveSingleClicked()
{
    bool o = _moveContext.singleClicked;
    _moveContext.singleClicked = false;
    return o;
}

bool FDecaMoveSDKModule::GetIfMoveDoubleClicked()
{
    bool o = _moveContext.doubleClicked;
    _moveContext.doubleClicked = false;
    return o;
}

bool FDecaMoveSDKModule::GetIfMoveTripleClicked()
{
    bool o = _moveContext.tripleClicked;
    _moveContext.tripleClicked = false;
    return o;
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDecaMoveSDKModule, DecaMoveSDK)

void UDecaMoveLoadSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    FDecaMoveSDKModule::LinkDll();
}

void UDecaMoveLoadSubsystem::Deinitialize()
{
    FDecaMoveSDKModule::ReleaseDll();

}