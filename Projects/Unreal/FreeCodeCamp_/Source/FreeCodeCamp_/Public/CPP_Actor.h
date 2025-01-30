// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Actor.generated.h"

UCLASS()
class FREECODECAMP__API ACPP_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACPP_Actor();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
