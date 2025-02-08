// Copyright Epic Games, Inc. All Rights Reserved.

#include "Battery_Collector_5GameMode.h"
#include "Battery_Collector_5Character.h"
#include "UObject/ConstructorHelpers.h"

ABattery_Collector_5GameMode::ABattery_Collector_5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
