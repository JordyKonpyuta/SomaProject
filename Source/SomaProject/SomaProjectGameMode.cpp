// Copyright Epic Games, Inc. All Rights Reserved.

#include "SomaProjectGameMode.h"
#include "SomaProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASomaProjectGameMode::ASomaProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
