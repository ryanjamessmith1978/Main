// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Pawn.h"
#include "Pickup.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().ClearTimer(SpawnTimer);
	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);

	// SetTimer needs a TimerHandle variable instance (created in Header here)
	// SetTimer needs to know the source object that is calling it, (this) for this instance
	// SetTimer needs to be linked to function call, (SpawnPickup in this case)
	// The time between function calls is the delay parameter passed in
	// The last bool is if it loops.  In this case, it's at being play, so it's a one time thing.
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	// all box components with have an origin and a box extent
	FVector spawnOrigin = WhereToSpawn->Bounds.Origin;

	FVector spawnExtent = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(spawnOrigin, spawnExtent);

}

void ASpawnVolume::SpawnPickup()
{
	// Check if we set something to spawn (aka you filled in the mesh on the class placed in world
	if (GetWorld())
	{
		// Check for World
		if (WhatToSpawn != NULL)
		{
			// Set Spawn Params
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = GetInstigator();

			// Spawn the pickup
			FVector spawnLocation = GetRandomPointInVolume();
			FRotator spawnRotation = FRotator(FMath::FRand() * 360.0f, FMath::FRand() * 360.0f, FMath::FRand() * 360.0f);

			APickup* spawnedPickup = 
			GetWorld()->SpawnActor<APickup>(WhatToSpawn, spawnLocation, spawnRotation, spawnParams);
			// GetWorld()->SpawnActor<APickup>(WhatToSpawn, spawnLocation, spawnRotation);

			GetWorldTimerManager().ClearTimer(SpawnTimer);
			SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);			

			// SetTimer needs a TimerHandle variable instance (created in Header here)
			// SetTimer needs to know the source object that is calling it, (this) for this instance
			// SetTimer needs to be linked to function call, (SpawnPickup in this case)
			// The time between function calls is the delay parameter passed in
			// The last bool is if it loops.  In this case, it's at being play, so it's a one time thing.
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);

		}
	}
}

