// Fill out your copyright notice in the Description page of Project Settings.


#include "WrapperObject.h"

FString UWrapperObject::GetName()
{
	return FString(OBJ.GetString().c_str());
}
