// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Dreams.h"
#include "DreamsGameMode.h"
#include "DreamsHUD.h"
#include "DreamsCharacter.h"

ADreamsGameMode::ADreamsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADreamsHUD::StaticClass();
}
