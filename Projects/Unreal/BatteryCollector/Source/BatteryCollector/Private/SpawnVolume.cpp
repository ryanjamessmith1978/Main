// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"

// where, what, when

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawner"));
	RootComponent = spawnVolume;

	spawnLowTime = 0.5f;
	spawnHighTime = 2.75f;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	spawnTime = FMath::FRandRange(spawnLowTime, spawnHighTime);

	GetWorldTimerManager().ClearTimer(TimerHandle);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ASpawnVolume::SpawnPickup, spawnTime, false);	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SpawnPickup();
}

void ASpawnVolume::SpawnPickup()
{
	// check for world
	UWorld* const world = GetWorld();
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();
	FVector spawnLoc = CreateSpawnPoint();

	if (world)
	{
		if (pickup != nullptr)
		{
			world->SpawnActor<APickupActor>(pickup, spawnLoc, FRotator(), SpawnParams);

			spawnTime = FMath::FRandRange(spawnLowTime, spawnHighTime);

			GetWorldTimerManager().ClearTimer(TimerHandle);
			GetWorldTimerManager().SetTimer(TimerHandle, this, &ASpawnVolume::SpawnPickup, spawnTime, false);
		}
	}

}

FVector ASpawnVolume::CreateSpawnPoint()
{
	FVector origin = spawnVolume->Bounds.Origin;
	FVector extent = spawnVolume->Bounds.BoxExtent;
	
	FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(origin, extent);

	return SpawnPoint;
}

