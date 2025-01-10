// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "Grabber.h"
#include "Kismet/GameplayStatics.h"

#define OUT

UGrabber::UGrabber()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	ArmsReach = 200.0f;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	MyPlayerController = World->GetFirstPlayerController();
	FindPhysicsHandleComponent();
	FindInputComponent();
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector LineTraceEnd = GetLineTraceEnd();
	
	if (MyPlayerController != nullptr)
	{
		if (!PhysicsHandle) { return; }
		// if the physics is attached
		if (PhysicsHandle->GrabbedComponent)
		{
			// move the object that we're holding.
			PhysicsHandle->SetTargetLocation(LineTraceEnd);
		}
	}
}

void UGrabber::FindPhysicsHandleComponent()
{
	///Initialize Owner's attached Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	// Validate physics handle component
	if (!PhysicsHandle) { return; }
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName())
	}
}

void UGrabber::FindInputComponent()
{
	// Look for component Input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	// validate inputcomponent
	if (InputComponent)
	{		
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::GrabObject);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::ReleaseObject);
	}
	else
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName())
}

FVector UGrabber::GetLineTraceEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	// GetPlayerViewPoint asks for an envelop, and then puts Location and Rotation of the playercontroller camera in the envelop
	MyPlayerController->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);
	FVector LineTraceDirection = PlayerViewPointRotation.Vector();
	// unit vector, vector of length 1, need to multiple by reach	 // Forward Vector * ArmsReach
	return PlayerViewPointLocation + LineTraceDirection * ArmsReach;
}

void UGrabber::GrabObject()
{
	//UE_LOG(LogClass, Warning, TEXT("Pressed Grab"));
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto HitActor = HitResult.GetActor();

	if (HitActor != nullptr)
	{	// TODO attach physics handle when reach collides with a physics body
		if (!PhysicsHandle) { return; }
		PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);
	}
}

void UGrabber::ReleaseObject()
{
	//UE_LOG(LogClass, Warning, TEXT("Released Grab Key"));
	// TODO release physics handle when pressed
	if (!PhysicsHandle) { return; }
	PhysicsHandle->ReleaseComponent();
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FHitResult LineTraceHit;

	if (World)
	{
		if (MyPlayerController)
		{
			FVector PlayerViewPointLocation;
			FRotator PlayerViewPointRotation;
			// GetPlayerViewPoint asks for an envelop, and then puts Location and Rotation of the playercontroller camera in the envelop
			MyPlayerController->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);
			FVector LineTraceDirection = PlayerViewPointRotation.Vector(); 
			// unit vector, vector of length 1, need to multiple by reach	 // Forward Vector * ArmsReach
			FVector LineTraceEnd = PlayerViewPointLocation + LineTraceDirection * ArmsReach;

			// DrawDebugLine(World, PlayerViewPointLocation, LineTraceEnd, FColor::Red, false, 3.0f, 3, 10.0f);
						
			FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
			// Ray Cast, returns out LineTrace Hit.  Be sure to define an FHitResult var, and a FCollisionQueryParams var.
			World->LineTraceSingleByObjectType(OUT LineTraceHit, PlayerViewPointLocation, LineTraceEnd,
				FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

			AActor* OutHit = LineTraceHit.GetActor();
			if (OutHit)
			{
				FString ActorHit = OutHit->GetName();
				UE_LOG(LogClass, Warning, TEXT("%s"), *ActorHit);
			}
		}
	}

	return LineTraceHit;
}