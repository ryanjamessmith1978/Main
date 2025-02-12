// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MyStuff/Core/BP_CharacterBase"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	decayRate = 0.02f;
	powerToWin = 2500.0f;
	currentPlayState = EPlayState::EUnknown;
}

void ABatteryCollectorGameMode::BeginPlay()
{
	Super::BeginPlay();
	myCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	if (MainHUDClass != nullptr)
	{
		mainHUD = CreateWidget<UUserWidget>(GetWorld(), MainHUDClass);

		if (mainHUD)
			mainHUD->AddToViewport();
	}

	currentPlayState = EPlayState::EPlaying;
	myController = UGameplayStatics::GetPlayerController(this, 0);
}

void ABatteryCollectorGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
	if (myCharacter)
	{
		myCharacter->PowerChange(-DeltaTime * decayRate * (myCharacter->GetInitalPower()) );

		// Check Play State
		if (myCharacter->GetCharacterPower() > powerToWin)
		{
			SetPlayState(EPlayState::EWon);
			if (myController)
			{
				myController->GetPawn()->DisableInput(myController);
			}
		}
		else if (myCharacter->GetCharacterPower() < 0)
		{
			SetPlayState(EPlayState::ELost);
			myCharacter->GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			myCharacter->GetMesh()->SetSimulatePhysics(true);
			if (myController)
			{
				myController->GetPawn()->DisableInput(myController);
			}
		}
	}
}

void ABatteryCollectorGameMode::SetPlayState(EPlayState newState)
{
	currentPlayState = newState;
}

ABatteryCollectorCharacter* ABatteryCollectorGameMode::GetCharacter() const
{
	return myCharacter;
}