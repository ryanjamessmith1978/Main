// Copyright Epic Games, Inc. All Rights Reserved.

#include "Robot_HeadBallGameMode.h"
#include "Robot_HeadBallCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARobot_HeadBallGameMode::ARobot_HeadBallGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
