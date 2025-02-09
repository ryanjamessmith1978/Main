// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pickup.h"
#include "SpawnPickups.generated.h"

UCLASS()
class BATTERY_COLLECTOR_5_API ASpawnPickups : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPickups();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UBoxComponent* GetSpawnVolume() const { return spawnVolume; }

	UFUNCTION(BlueprintPure, Category = Spawn)
	FVector GetRandomPointInVolume();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	TSubclassOf<APickup> whatToSpawn;

	FTimerHandle spawnTimer;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Spawn)
	float minSpawnDelay;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Spawn)
	float maxSpawnDelay;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawn, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* spawnVolume;

	void SpawnPickup();

	float finalSpawnDelayTime;
};

// Where to Spawn
// What to Spawn
// When to Spawn (timers)