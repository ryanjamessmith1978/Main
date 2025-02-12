// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupActor.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickupActor
{
	GENERATED_BODY()

private:
	// Sets default values for this actor's properties
	ABatteryPickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void WasCollected_Implementation() override;

};
