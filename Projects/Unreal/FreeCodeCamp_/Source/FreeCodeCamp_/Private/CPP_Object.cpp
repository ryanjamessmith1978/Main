// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Object.h"

int UCPP_Object::GetOurPrivateIntegerVariable()
{
	return 0;
}

void UCPP_Object::SetOurPrivateIntegerVariable(UPARAM(ref)int& intVar)
{
	OurPrivateIntegerVariable = intVar;
}

void UCPP_Object::Test(UPARAM(ref)FBook& Target, AActor* actor)
{
	// UKismetSystemLibrary::PrintString("TestFunctionCalled"); // Fail, you need to pass in a World (Get World) context object // pass in an object
	UKismetSystemLibrary::PrintString(actor, "TestFunctionCalled"); 
}
