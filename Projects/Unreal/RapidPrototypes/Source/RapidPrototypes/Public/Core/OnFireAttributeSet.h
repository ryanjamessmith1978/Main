// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Math/UnrealMathUtility.h"
#include "OnFireAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class RAPIDPROTOTYPES_API UOnFireAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DataSet Property")
	FGameplayAttributeData Health = 100.0f;
	ATTRIBUTE_ACCESSORS(UOnFireAttributeSet, Health)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DataSet Property")
	FGameplayAttributeData Mana = 100.0f;
	ATTRIBUTE_ACCESSORS(UOnFireAttributeSet, Mana)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DataSet Property")
	FGameplayAttributeData Stamina = 100.0f;
	ATTRIBUTE_ACCESSORS(UOnFireAttributeSet, Stamina)

};
