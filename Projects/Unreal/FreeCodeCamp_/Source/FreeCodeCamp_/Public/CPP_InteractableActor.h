// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "CPP_InteractableActor.generated.h"

UCLASS()
class FREECODECAMP__API ACPP_InteractableActor : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_InteractableActor();

	virtual void Tick(float DeltaTime) override;
	virtual void Destruct() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY()
	float initProp;

};
