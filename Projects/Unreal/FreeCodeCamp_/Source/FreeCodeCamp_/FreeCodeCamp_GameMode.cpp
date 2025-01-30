// Copyright Epic Games, Inc. All Rights Reserved.

#include "FreeCodeCamp_GameMode.h"
#include "FreeCodeCamp_Character.h"
#include "UObject/ConstructorHelpers.h"

AFreeCodeCamp_GameMode::AFreeCodeCamp_GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
