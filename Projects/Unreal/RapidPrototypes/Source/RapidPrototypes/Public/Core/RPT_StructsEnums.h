// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "RPT_StructsEnums.generated.h"

// Enum: EDamageType
UENUM(BlueprintType)
enum class EDamageType : uint8 {
    None,
    Physical,
    Fire,
    Frost,
    Lightning,
    Magic
};

UENUM(BlueprintType)
enum class EDamageResponse : uint8 {
    None,
    HitReactionDefault,
    Stagger,
    Stun,
    KnockBack
};

// Struct: FDamageInfo
USTRUCT(BlueprintType)
struct FDamageInfo 
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    float AmountOfDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    EDamageType DamageType;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    EDamageResponse DamageResponse;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    bool bIsDamageInvincible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    bool bIsBlockable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    bool bIsParryable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    bool bIsAnimationInterrupt;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    TMap<EDamageType, float> DamageValues; // Supports multiple types per hit

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    AActor* SourceActor;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic Data")
    AActor* TargetActor;
    //TSubclassOf<UDamageEffect> StatusEffect; // Optional for triggering things like Frostbite
};