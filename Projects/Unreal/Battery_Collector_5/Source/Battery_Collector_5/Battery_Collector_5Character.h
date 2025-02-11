// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Pickup.h"
#include "BatteryPickup.h"
#include "Logging/LogMacros.h"
#include "Components/SphereComponent.h"
#include "Battery_Collector_5Character.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ABattery_Collector_5Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sphere, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollectionSphere;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CollectAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	ABattery_Collector_5Character();

	UFUNCTION(BlueprintPure, Category = "Power")
	FORCEINLINE float GetInitialPower() const { return initialPower; }

	UFUNCTION(BlueprintCallable, Category = "Power")
	FORCEINLINE float GetCurrentPower() const { return charPower; }

	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdatePower(float powerChange);
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	UFUNCTION(BlueprintImplementableEvent)
	void PowerChangeEffect();
			

protected:

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float initialPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float baseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float speedFactor;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power, meta = (AllowPrivateAccess = "true"))
	float charPower;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	FORCEINLINE class USphereComponent* GetCollectionSphere() const {return CollectionSphere; }
};

