// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERY_COLLECTOR_5_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:

	ABatteryPickup();

	void WasCollected_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = Power)
	FORCEINLINE float GetBatteryPower() const { return batteryPower; }

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power, meta = (BlueprintProtected = "true") )
	float batteryPower;

private:
	
};
