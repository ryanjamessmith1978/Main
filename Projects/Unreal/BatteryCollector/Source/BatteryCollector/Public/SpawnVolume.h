// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PickupActor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnPickup();

	UPROPERTY()
	FTimerHandle TimerHandle;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn, meta = (BlueprintProtected = "true"))
	UBoxComponent* spawnVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn, meta = (BlueprintProtected = "true"))
	TSubclassOf<APickupActor> pickup;   

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	float spawnLowTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	float spawnHighTime;

private:

	FVector CreateSpawnPoint();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawn, meta = (AllowPrivateAccess = "true"))
	float spawnTime;
};
