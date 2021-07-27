// Copyright Epic Games, Inc. All Rights Reserved.

#include "DecaMoveSDK.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Math/UnrealMathUtility.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FDecaMoveSDKModule"

FDecaMoveSDKModule::MoveContext FDecaMoveSDKModule::_moveContext;
void* FDecaMoveSDKModule::DecaMoveLibraryHandle = nullptr;
deca_move FDecaMoveSDKModule::move;

void FDecaMoveSDKModule::StartupModule()
{
}

void FDecaMoveSDKModule::StartSDK()
{
	// Get the base directory of this plugin

#ifdef PLATFORM_WINDOWS

	FString BaseDir = IPluginManager::Get().FindPlugin("DecaMoveSDK")->GetBaseDir();
	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/Win64/deca_sdk.dll"));

    UE_LOG(LogTemp, Display, TEXT("Loading DecaMoveSDK"));
	DecaMoveLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
#endif 


    try
    {
        SetupMove();
}
    catch (const std::exception& e)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to intialize deca move library, exception was thrown"), *e.what());
    }
}


void FDecaMoveSDKModule::ShutdownModule()
{
}

void FDecaMoveSDKModule::ReleaseSDK()
{
    UE_LOG(LogTemp, Display, TEXT("Unloading DecaMoveSDK"));
    CleanUpMove();

#ifdef PLATFORM_WINDOWS
	// Free the dll handle
	FPlatformProcess::FreeDllHandle(DecaMoveLibraryHandle);
	DecaMoveLibraryHandle = nullptr;
#endif
}



void FDecaMoveSDKModule::SetupMove()
{
    deca_move_callbacks callbacks = {};
    callbacks.feedback_cb = [](deca_move_feedback feedback, void* userData)
    {
        MoveContext* ctx = ((MoveContext*)userData);
        ctx->lock.lock();
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
        ctx->lock.unlock();

    };
    callbacks.battery_update_cb = [](float charge, void* userData)
    {
        //UE_LOG(LogTemp, Log, TEXT("Battery: %g%%\n"), charge);
    };
    callbacks.orientation_update_cb = [](deca_move_quaternion quat, deca_move_accuracy accuracy, float yawCalibration, void* userData)
    {
        MoveContext* ctx = (MoveContext*)userData;
        ctx->lock.lock();
        ctx->rotation = DecaToUnreal(quat);
        ctx->yawOffset = yawCalibration;
        ctx->lock.unlock();
        UE_LOG(LogTemp, Log, TEXT("Orientation: %.2f %.2f %.2f %.2f yaw=%.2f [%d]\n"), quat.x, quat.y, quat.z, quat.w, yawCalibration, int(accuracy));
    };
    callbacks.position_update_cb = [](float position_x, float position_y, float position_z, void* userData)
    {
        MoveContext* ctx = (MoveContext*)userData;
        ctx->lock.lock();
        ctx->position = FVector(position_x, position_y, position_z);
        ctx->lock.unlock();
        //UE_LOG(LogTemp, Log, TEXT("Position: %.2f %.2f %.2f\n"), position_x, position_y, position_z);
    };
    callbacks.state_update_cb = [](deca_move_state state, void* userData)
    {
        MoveContext* ctx = (MoveContext*)userData;
        ctx->lock.lock();
        ctx->state = state;
        ctx->lock.unlock();
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
    deca_move_status status;
    status = decaMoveInit(envDesc, callbacks, &move);
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
    move = nullptr;
}


FRotator FDecaMoveSDKModule::GetMoveRotation()
{
    UE_LOG(LogTemp, Warning, TEXT("Getting move rotation\n"));

    FRotator o = FRotator(FQuat(FVector(0, 0, 1), _moveContext.yawOffset) * _moveContext.rotation);
    return o;
};

float FDecaMoveSDKModule::GetMoveYawOffset()
{
    _moveContext.lock.lock();
    auto value = _moveContext.yawOffset;
    _moveContext.lock.unlock();
    return value;
}

FQuat FDecaMoveSDKModule::GetMoveRawRotation()
{
    _moveContext.lock.lock();
    auto value = _moveContext.rotation;
    _moveContext.lock.unlock();
    return value;
};

FVector FDecaMoveSDKModule::GetMovePosition()
{
    _moveContext.lock.lock();
    auto value = _moveContext.position;
    _moveContext.lock.unlock();
    return value;
}

deca_move_state FDecaMoveSDKModule::GetMoveState()
{
    _moveContext.lock.lock();
    auto value = _moveContext.state;
    _moveContext.lock.unlock();
    return value;
}

bool FDecaMoveSDKModule::IsMoveSleeping()
{
    _moveContext.lock.lock();
    auto value = _moveContext.isSleeping;
    _moveContext.lock.unlock();
    return value;
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
    _moveContext.lock.lock();
    bool o = _moveContext.singleClicked;
    _moveContext.singleClicked = false;
    _moveContext.lock.unlock();
    return o;
}

bool FDecaMoveSDKModule::GetIfMoveDoubleClicked()
{
    _moveContext.lock.lock();
    bool o = _moveContext.doubleClicked;
    _moveContext.doubleClicked = false;
    _moveContext.lock.unlock();
    return o;
}

bool FDecaMoveSDKModule::GetIfMoveTripleClicked()
{
    _moveContext.lock.lock();
    bool o = _moveContext.tripleClicked;
    _moveContext.tripleClicked = false;
    _moveContext.lock.unlock();
    return o;
}

FDecaMoveSDKModule::MoveContext::MoveContext()
{
    state = kDecaMoveStateClosed;
    isSleeping = true;
    position = FVector(0, 0, 0);
    rotation = FQuat(0, 0, 0, 1);
    yawOffset = 0;
    singleClicked = false;
    doubleClicked = false;
    tripleClicked = false;
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDecaMoveSDKModule, DecaMoveSDK)

