
#include "Pickup.h"
#include "BatteryCollector.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bIsActive = true;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APickup::IsActive()
{
	return bIsActive;
}

void APickup::SetActive(bool newPickupState)
{
	bIsActive = newPickupState;
}

void APickup::WasCollected_Implementation()
{
	// log a debug message
	FString pickupDebugString = GetName();

	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *pickupDebugString);

}