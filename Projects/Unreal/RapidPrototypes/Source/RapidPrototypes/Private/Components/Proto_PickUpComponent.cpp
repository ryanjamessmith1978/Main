// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Proto_PickUpComponent.h"

UProto_PickUpComponent::UProto_PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UProto_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UProto_PickUpComponent::OnSphereBeginOverlap);
}

void UProto_PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AProto_FPP_Character* Character = Cast<AProto_FPP_Character>(OtherActor);
	if (Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
