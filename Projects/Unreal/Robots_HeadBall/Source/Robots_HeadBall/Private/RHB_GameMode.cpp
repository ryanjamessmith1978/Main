// Fill out your copyright notice in the Description page of Project Settings.


#include "RHB_GameMode.h"
#include "Robots_HeadBall\Robots_HeadBallCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARHB_GameMode::ARHB_GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
