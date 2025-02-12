// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupActor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = pickupMesh;
	bIsActive = true;
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APickupActor::SetbIsActive(bool act)
{
	bIsActive = act;
}

void APickupActor::WasCollected_Implementation()
{
	UKismetSystemLibrary::PrintString(this, "Pickup Actor Collected");
}

