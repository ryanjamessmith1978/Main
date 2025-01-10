// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:

	// Set Default Values for this Actor
	ABatteryPickup();

	// Override WasCollected Function - use Implementation because it's a Blueprint Native Event
	void WasCollected_Implementation() override;

	// public way to access the battery's power level
	float GetPower();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float BatteryPower;


};
