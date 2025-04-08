// Fill out your copyright notice in the Description page of Project Settings.


#include "RHB_GameBall.h"


// Sets default values
ARHB_GameBall::ARHB_GameBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARHB_GameBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARHB_GameBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

