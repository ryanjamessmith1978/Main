// Copyright Epic Games, Inc. All Rights Reserved.

#include "BC5GameMode.h"
#include "BC5Character.h"
#include "UObject/ConstructorHelpers.h"

ABC5GameMode::ABC5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
