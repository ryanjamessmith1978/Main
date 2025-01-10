// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Return the Mesh for the Pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const {	return PickupMesh;	}

	// returns whether a pickup is active or not.
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	// Allows other classes to safely change whether or not Pickup is Active
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool newPickupState);

	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:

	// true when Pickup is used, false when pickup is deactivated.
	bool bIsActive;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;




};
