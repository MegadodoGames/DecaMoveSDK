#include "DecaMoveSDKLoader.h"

void UDecaMoveLoadSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    FDecaMoveSDKModule::StartSDK();
}

void UDecaMoveLoadSubsystem::Deinitialize()
{
    FDecaMoveSDKModule::ReleaseSDK();

}