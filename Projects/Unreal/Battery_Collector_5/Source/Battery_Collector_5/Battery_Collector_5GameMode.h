// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Battery_Collector_5GameMode.generated.h"

UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABattery_Collector_5GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABattery_Collector_5GameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetPowerToWin() const { return powerToWin; }

	UFUNCTION(BlueprintPure, Category = PlayState)
	FORCEINLINE EBatteryPlayState GetPlayState() const { return currentPlayState; }

	UFUNCTION(BlueprintCallable, Category = PlayState)
	void SetPlayState(EBatteryPlayState newState);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float decayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float powerToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> classWidget;  // one for the widget

	UPROPERTY()
	UUserWidget* mainHUD; // one for the specific widget instance

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayState, meta = (AllowPrivateAccess = "true") )
	EBatteryPlayState currentPlayState;

};



