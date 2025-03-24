// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabberActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROBOT_HEADBALL_API UGrabberActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabberActorComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UWorld* World = nullptr;

	APlayerController* MyPlayerController = nullptr;

	void FindPhysicsHandleComponent();

	void FindInputComponent();

	FVector GetLineTraceEnd();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Door", meta = (AllowPrivateAccess = "true"))
	float ArmsReach;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	void GrabObject();

	void ReleaseObject();

	const FHitResult GetFirstPhysicsBodyInReach();
};
