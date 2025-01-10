// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "PositionReporter.h"


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();

	AActor* OwnerActor = GetOwner(); // Get Owner returns a pointer to an AActor.  
	FString DebugActorName = OwnerActor->GetName();
	FString ObjectPos = OwnerActor->GetActorLocation().ToString();
	
	UE_LOG(LogClass, Warning, TEXT("Position report reporting for duty on : %s is at %s"), *DebugActorName, *ObjectPos);

	// ...
}


// Called every frame
void UPositionReporter::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

