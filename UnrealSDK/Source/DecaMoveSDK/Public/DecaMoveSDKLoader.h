#pragma once
#include "DecaMoveSDK.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DecaMoveSDKLoader.generated.h"


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