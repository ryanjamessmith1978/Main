// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = Pickup)
	FORCEINLINE bool GetbIsActive() const { return bIsActive; }

	UFUNCTION(BlueprintCallable, Category = Pickup)
	void SetbIsActive(bool act);

	UFUNCTION(BlueprintPure, Category = Pickup)
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return pickupMesh; }

	UFUNCTION(BlueprintNativeEvent, Category = Pickup)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pickup)
	bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup, meta = (BlueprintProtected = "true"))
	UStaticMeshComponent* pickupMesh;

};
