// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Characters/Proto_FPP_Character.h"
#include "Proto_PickUpComponent.generated.h"

// Declaration of the delegate that will be called when someone picks this up
// The character picking this up is the parameter sent with the notification
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, AProto_FPP_Character*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RAPIDPROTOTYPES_API UProto_PickUpComponent : public USphereComponent
{
	GENERATED_BODY()
	
public:

	UProto_PickUpComponent();
	
	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp;

	/** Called when the game starts */
	virtual void BeginPlay() override;

	/** Code for when something overlaps this component */
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
