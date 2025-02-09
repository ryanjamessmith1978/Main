// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERY_COLLECTOR_5_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Return mesh for the pickup
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	UFUNCTION(BlueprintPure, Category = Pickup)
	FORCEINLINE bool GetIsActive() const { return bIsActive; }

	// BP Callable are slower but can modify based on 
	UFUNCTION(BlueprintCallable, Category = Pickup)
	void SetIsActive(bool isActive);

	// Function to call when pickup is collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:

	// True when pickup can be used, and false when deactivated
	UPROPERTY()
	bool bIsActive;

private:
	// Mesh component to represent static mesh model shown in level
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	 UStaticMeshComponent* PickupMesh;

};
