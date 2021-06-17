// Fill out your copyright notice in the Description page of Project Settings.


#include "DecaMoveBlueprintFunctionLibrary.h"

FRotator UDecaMoveBlueprintFunctionLibrary::GetDecaMoveRotation()
{
	return FDecaMoveSDKModule::GetMoveRotation();
}
FQuat UDecaMoveBlueprintFunctionLibrary::GetDecaMoveRawRotation()
{
	return FDecaMoveSDKModule::GetMoveRawRotation();
}

float UDecaMoveBlueprintFunctionLibrary::GetDecaMoveYawOffset()
{
	return FDecaMoveSDKModule::GetMoveYawOffset();
}

FVector UDecaMoveBlueprintFunctionLibrary::GetDecaMovePostion()
{
	return FDecaMoveSDKModule::GetMovePosition();
}

EDecaMoveState UDecaMoveBlueprintFunctionLibrary::GetDecaMoveState()
{
	return (EDecaMoveState)FDecaMoveSDKModule::GetMoveState();
}

bool UDecaMoveBlueprintFunctionLibrary::IsDecaMoveSleeping()
{
	return FDecaMoveSDKModule::IsMoveSleeping();
}

void UDecaMoveBlueprintFunctionLibrary::CalibrateDecaMove(FVector forward)
{
	FDecaMoveSDKModule::CalibrateMove(forward.X, forward.Y);
}

void UDecaMoveBlueprintFunctionLibrary::SendDecaMoveHaptic()
{
	FDecaMoveSDKModule::SendHaptic();
}

bool UDecaMoveBlueprintFunctionLibrary::GetIfDecaMoveSingleClicked()
{
	return FDecaMoveSDKModule::GetIfMoveSingleClicked();
}

bool UDecaMoveBlueprintFunctionLibrary::GetIfDecaMoveDoubleClicked()
{
	return FDecaMoveSDKModule::GetIfMoveDoubleClicked();
}

bool UDecaMoveBlueprintFunctionLibrary::GetIfDecaMoveTripleClicked()
{
	return FDecaMoveSDKModule::GetIfMoveTripleClicked();
}
