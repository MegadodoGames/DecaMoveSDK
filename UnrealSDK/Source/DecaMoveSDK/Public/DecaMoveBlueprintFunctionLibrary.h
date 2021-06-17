// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DecaMoveSDK.h"
#include "Core.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DecaMoveBlueprintFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EDecaMoveState : uint8
{
	closed = 0 UMETA(DisplayName = "Closed"),
	open UMETA(DisplayName = "Open"),
	paired UMETA(DisplayName = "Paired"),
	streaming UMETA(DisplayName = "Streaming")
};

/**
 * 
 */
UCLASS()
class DECAMOVESDK_API UDecaMoveBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static FRotator GetDecaMoveRotation();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static FQuat GetDecaMoveRawRotation();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static float GetDecaMoveYawOffset();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static FVector GetDecaMovePostion();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static EDecaMoveState GetDecaMoveState();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static bool IsDecaMoveSleeping();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static void CalibrateDecaMove(FVector forward);
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static void SendDecaMoveHaptic();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static bool GetIfDecaMoveSingleClicked();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static bool GetIfDecaMoveDoubleClicked();
	UFUNCTION(BlueprintCallable, Category = "DecaMove")
		static bool GetIfDecaMoveTripleClicked();

	

};

