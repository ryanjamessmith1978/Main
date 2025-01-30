// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OurIntArray = { 23,6,43,64 };
	OurMap.Add("Pi", 3.14);
}

// Called when the game starts or when spawned (Resume at 6:15)
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();
	TestBPFunc(100); // Can be called from BP too.  Implement Event in BP to create definition and execute.
	TestBPImp(1000.0f); 
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Character::RemovePickup()
{
	auto playerCamera = UGameplayStatics::GetPlayerCameraManager(this, 0);
	FVector cameraLoc = playerCamera->GetCameraLocation();
	FVector forwardVec = playerCamera->GetActorForwardVector();
	FVector endLoc = FVector(0);
	forwardVec *= 50000.00;
	forwardVec += cameraLoc;
	FHitResult outHit;
	const TArray <AActor*> ActorsToIgnore;

	UKismetSystemLibrary::LineTraceSingle(this, cameraLoc, forwardVec, ETraceTypeQuery::TraceTypeQuery1, false,
		ActorsToIgnore, EDrawDebugTrace::Persistent, outHit, true, FLinearColor::Red, FLinearColor::Green, 5.0f);

	if (outHit.GetActor())
	{
		if (Cast<IMyInterface>(outHit.GetActor()))
		{
			auto myInter = Cast<IMyInterface>(outHit.GetActor());
			UKismetSystemLibrary::PrintString(this, "Destroyed a pickup");
			myInter->Destruct();
		}
	}
}

void ACPP_Character::TestBPImp_Implementation(float x)
{
	UKismetSystemLibrary::PrintString(this, "C++ Implementation called");
}

void ACPP_Character::addToTArray()
{
	OurIntArray.Reserve(6);
	OurIntArray.Add(12);
	OurIntArray.Emplace(13);
	OurIntArray.Remove(23);
	OurIntArray.RemoveAt(0);

	for (auto& x : OurIntArray)
	{
		UKismetSystemLibrary::PrintString(this, FString::FromInt(x));
	}
}

void ACPP_Character::addToTMap()
{
	OurMap.Add("Pi", 3.14);
	OurMap.Add("Num1", 6.28);
	OurMap.Add("Num2", 9.42);

	for (auto& ele : OurMap)
	{
		FString mapKey = ele.Key;
		FString mapVal = FString::SanitizeFloat(ele.Value);
		UKismetSystemLibrary::PrintString(this, mapKey + ":" + mapVal);
	}
}
