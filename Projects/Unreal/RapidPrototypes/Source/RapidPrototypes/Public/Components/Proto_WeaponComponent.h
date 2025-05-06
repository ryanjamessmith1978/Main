// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Proto_WeaponComponent.generated.h"

class AProto_FPP_Character;

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RAPIDPROTOTYPES_API UProto_WeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:

	UProto_WeaponComponent();
	
	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AProjectileBullet> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* FireMappingContext;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* FireAction;

	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool AttachWeapon(AProto_FPP_Character* TargetCharacter);

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	/** The Character holding this weapon*/
	AProto_FPP_Character* Character;

};
