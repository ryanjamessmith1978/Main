// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "MyInterface.h"
#include "CPP_Character.generated.h"

UCLASS()
class FREECODECAMP__API ACPP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int> OurIntArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<FString, float> OurMap;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Collision", Meta = (bIgnoreSelf = "true", WorldContext = "WorldContextObject", AutoCreateRefTerm = "ActorsToIgnore", DisplayName = "RemovePickup", AdvancedDisplay = "TraceColor,TraceHitColor,DrawTime", Keywords = "raycast"))
	void RemovePickup();

	// Difference between Blueprint Implementable and Blueprint Native?
	// Blueprint Implementable Event calls a Blueprint from C++.  Implementable DOES NOT need to be defined in C++
	// Blueprint Native needs to be defined in C++ 
	// BP Calls are not function calls but Events.  
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TestBPFunc(int x);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TestBPImp(float x);
	void TestBPImp_Implementation(float x); // Implementation is defined in C++, calls are without _Implementation.  

	void addToTArray();

	void addToTMap();
};
