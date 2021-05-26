// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestTopDownGameMode.h"
#include "TestTopDownPlayerController.h"
#include "TestTopDownCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestTopDownGameMode::ATestTopDownGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATestTopDownPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}