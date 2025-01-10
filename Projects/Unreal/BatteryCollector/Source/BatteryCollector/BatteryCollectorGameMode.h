// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

// enum to store current states of the game
UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ABatteryCollectorGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float DecayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float PowerToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};



