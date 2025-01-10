// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"
#include "Kismet/GameplayStatics.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = 180.0f;	
	DoorCloseDelay = 1.0f;
	bDoorOpen = false;
	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Warning, TEXT("No pressure Plate found"))
	}
	
	OwnerRot = Owner->GetActorRotation();
	// ...	
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	// if the total mass on the plate is greater than 50
		// Open Door

	float Mass = GetTotalMass();

	if (Mass >= 50.0f)
	{
		bDoorOpen = true;
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else if (bDoorOpen && Mass < 50.0f)
	{
		bDoorOpen = false;
		CloseDoor();
	}
		
}

void UOpenDoor::OpenDoor()
{	
	OnOpenRequest.Broadcast();
	//OwnerRot.Yaw = OpenAngle;
	//Owner->SetActorRotation(OwnerRot);
}

void UOpenDoor::CloseDoor()
{
	OnCloseRequest.Broadcast();
}

float UOpenDoor::GetTotalMass()
{
	float TotalMass = 0.0f;
	TArray<AActor*> ActorsOverlappingPlate;
	// get all overlapping actors
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT ActorsOverlappingPlate);
		//Iterate over all actors and add their kg to total mass
	
	for (const auto& Actor : ActorsOverlappingPlate)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *FString::SanitizeFloat(TotalMass))
	}

	return TotalMass;
}
