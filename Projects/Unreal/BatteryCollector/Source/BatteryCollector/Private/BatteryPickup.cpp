// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABatteryPickup::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();

	SetLifeSpan(0.5f);
}
