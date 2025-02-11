// Copyright Epic Games, Inc. All Rights Reserved.

#include "Battery_Collector_5GameMode.h"
#include "Battery_Collector_5Character.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ABattery_Collector_5GameMode::ABattery_Collector_5GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	decayRate = 0.01f;
}

void ABattery_Collector_5GameMode::BeginPlay()
{
	currentPlayState = EBatteryPlayState::EPlaying;	
	powerToWin = 2500.0f;



	if (classWidget != nullptr)
	{
		mainHUD = CreateWidget<UUserWidget>(GetWorld(), classWidget);
		if (mainHUD != nullptr)
		{
			mainHUD->AddToViewport();
		}
	}
}

void ABattery_Collector_5GameMode::Tick(float DeltaTime)
{
	ABattery_Collector_5Character* myCharacter = Cast<ABattery_Collector_5Character>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (myCharacter->GetCurrentPower() > powerToWin)
	{
		SetPlayState(EBatteryPlayState::EWon);
	}
	else if (myCharacter)
	{
		myCharacter->UpdatePower(-DeltaTime * decayRate * (myCharacter->GetInitialPower()));
	}
	else if (myCharacter->GetCurrentPower() < 10.0f)
	{
		SetPlayState(EBatteryPlayState::EGameOver);
	}
	else
		SetPlayState(EBatteryPlayState::EUnknown);
}

void ABattery_Collector_5GameMode::SetPlayState(EBatteryPlayState newState)
{
	currentPlayState = newState;
}
