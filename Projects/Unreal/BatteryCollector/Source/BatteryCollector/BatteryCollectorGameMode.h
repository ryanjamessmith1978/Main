// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "BatteryCollectorCharacter.h"
#include "BatteryCollectorGameMode.generated.h"

UENUM(BlueprintType)
enum class EPlayState : uint8
{
	EPlaying,
	EWon,
	ELost,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	UFUNCTION(BlueprintCallable, Category = "HUD")
	ABatteryCollectorCharacter* GetCharacter() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void SetPlayState(EPlayState newState);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD", meta = (BlueprintProtected = "true"))
	TSubclassOf<UUserWidget> MainHUDClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD", meta = (BlueprintProtected = "true"))
	UUserWidget* mainHUD;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUD", meta = (BlueprintProtected = "true"))
	float decayRate;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD", meta = (AllowPrivateAccess = "true"))
	ABatteryCollectorCharacter* myCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD", meta = (AllowPrivateAccess = "true"))
	APlayerController* myController;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD", meta = (AllowPrivateAccess = "true"))
	EPlayState currentPlayState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (AllowPrivateAccess = "true"))
	float powerToWin;
};



