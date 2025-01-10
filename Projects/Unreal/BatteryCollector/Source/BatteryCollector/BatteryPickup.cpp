
#include "BatteryPickup.h"

ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);

	// Base Power level of the battery
	BatteryPower = 150.f;

}

void ABatteryPickup::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();

	//Destroy the Battery
	Destroy();

}

float ABatteryPickup::GetPower()
{
	return BatteryPower;
}