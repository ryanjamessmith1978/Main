// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPickups.h"

// Sets default values
ASpawnPickups::ASpawnPickups()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	spawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = spawnVolume;
	minSpawnDelay = 0.5f;
	maxSpawnDelay = 3.5f;
	finalSpawnDelayTime = 0.0f;
}

// Called when the game starts or when spawned
void ASpawnPickups::BeginPlay()
{
	Super::BeginPlay();
	finalSpawnDelayTime = FMath::RandRange(minSpawnDelay, maxSpawnDelay);
	GetWorldTimerManager().ClearTimer(spawnTimer);
	GetWorldTimerManager().SetTimer(spawnTimer, this, &ASpawnPickups::SpawnPickup, finalSpawnDelayTime, false);
}

// Called every frame
void ASpawnPickups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnPickups::GetRandomPointInVolume()
{
	FVector randomPoint;
	FVector spawnOrigin = spawnVolume->Bounds.Origin;
	FVector spawnExtent = spawnVolume->Bounds.BoxExtent;
	randomPoint = UKismetMathLibrary::RandomPointInBoundingBox(spawnOrigin, spawnExtent);

	return randomPoint;
}

void ASpawnPickups::SpawnPickup()
{
	// How do we check if we set something to spawn

	// Check if Null, Check for valid world
	if (whatToSpawn != nullptr)
	{
		UWorld* const world = GetWorld();
		if (world != nullptr)
		{
			// Spawn Params
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// Spawn Pickup at Where to Spawn location
			FVector SpawnLocation = GetRandomPointInVolume();
			FRotator SpawnRotator = FRotator(FMath::FRand() * 360.0f, FMath::FRand() * 360.0f, FMath::FRand() * 360.0f);

			APickup* spawnedPickup = world->SpawnActor<APickup>(whatToSpawn, SpawnLocation, SpawnRotator, SpawnParams);
			
			finalSpawnDelayTime = FMath::RandRange(minSpawnDelay, maxSpawnDelay);
			GetWorldTimerManager().ClearTimer(spawnTimer);
			GetWorldTimerManager().SetTimer(spawnTimer, this, &ASpawnPickups::SpawnPickup, finalSpawnDelayTime, false);
		}
	}
}