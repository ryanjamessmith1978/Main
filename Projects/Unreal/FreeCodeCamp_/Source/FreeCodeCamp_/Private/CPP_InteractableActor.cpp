// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InteractableActor.h"

// Sets default values
ACPP_InteractableActor::ACPP_InteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_InteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_InteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_InteractableActor::Destruct()
{
	UKismetSystemLibrary::PrintString(this, "Destroyed Interactable Actor");
	Destroy();
}
