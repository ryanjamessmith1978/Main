// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TestPluginInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTestPluginInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTPLUGIN_API ITestPluginInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent)
	void TestFunction();
};
