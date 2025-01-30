// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_Object.generated.h"

UENUM(BlueprintType)
enum FruitList
{
	Apple UMETA(DisplayName="Apple"),
	Mango UMETA(DisplayName = "Mango"),
	Banana UMETA(DisplayName = "Banana")
};

USTRUCT(BlueprintType)
struct FBook
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int value;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float diff;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString name;
};
// CPP_BaseObject
UCLASS(Blueprintable) // Even though UObject, since it's set as blueprintable, any other object in Blueprints can see this CLASS!
class FREECODECAMP__API UCPP_Object : public UObject
{
	GENERATED_BODY()
	
private:
	int OurPrivateIntegerVariable;

public:
	UPROPERTY(BlueprintReadWrite)
		int OurPublicIntegerVariable;

	UFUNCTION(BlueprintPure)
		int GetOurPrivateIntegerVariable();
	UFUNCTION(BlueprintCallable)
		void SetOurPrivateIntegerVariable(UPARAM(ref)int& intVar);

	UFUNCTION(BlueprintCallable) // Create your own target pin (CLASS LEVEL STATIC CALL)
		static void Test(UPARAM(ref) FBook& Target, AActor* actor); // Create a local variable Struct in BP to pass in Ref, Actor is self)
};
