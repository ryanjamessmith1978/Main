// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BatteryCollector/Public/BatteryPickup.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBatteryPickup() {}

// Begin Cross Module References
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ABatteryPickup();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ABatteryPickup_NoRegister();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_APickupActor();
UPackage* Z_Construct_UPackage__Script_BatteryCollector();
// End Cross Module References

// Begin Class ABatteryPickup Function GetBatteryPower
struct Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics
{
	struct BatteryPickup_eventGetBatteryPower_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Power" },
		{ "ModuleRelativePath", "Public/BatteryPickup.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BatteryPickup_eventGetBatteryPower_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABatteryPickup, nullptr, "GetBatteryPower", nullptr, nullptr, Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::BatteryPickup_eventGetBatteryPower_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::BatteryPickup_eventGetBatteryPower_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABatteryPickup_GetBatteryPower()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABatteryPickup_GetBatteryPower_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABatteryPickup::execGetBatteryPower)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetBatteryPower();
	P_NATIVE_END;
}
// End Class ABatteryPickup Function GetBatteryPower

// Begin Class ABatteryPickup Function WasCollected_Implementation
struct Z_Construct_UFunction_ABatteryPickup_WasCollected_Implementation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Power" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Overriden BP Native Event for when a battery is collected.\n" },
#endif
		{ "ModuleRelativePath", "Public/BatteryPickup.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overriden BP Native Event for when a battery is collected." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABatteryPickup_WasCollected_Implementation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABatteryPickup, nullptr, "WasCollected_Implementation", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryPickup_WasCollected_Implementation_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABatteryPickup_WasCollected_Implementation_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABatteryPickup_WasCollected_Implementation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABatteryPickup_WasCollected_Implementation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABatteryPickup::execWasCollected_Implementation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->WasCollected_Implementation();
	P_NATIVE_END;
}
// End Class ABatteryPickup Function WasCollected_Implementation

// Begin Class ABatteryPickup
void ABatteryPickup::StaticRegisterNativesABatteryPickup()
{
	UClass* Class = ABatteryPickup::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetBatteryPower", &ABatteryPickup::execGetBatteryPower },
		{ "WasCollected_Implementation", &ABatteryPickup::execWasCollected_Implementation },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABatteryPickup);
UClass* Z_Construct_UClass_ABatteryPickup_NoRegister()
{
	return ABatteryPickup::StaticClass();
}
struct Z_Construct_UClass_ABatteryPickup_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BatteryPickup.h" },
		{ "ModuleRelativePath", "Public/BatteryPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_batteryPower_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Power" },
		{ "ModuleRelativePath", "Public/BatteryPickup.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_batteryPower;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABatteryPickup_GetBatteryPower, "GetBatteryPower" }, // 1939961597
		{ &Z_Construct_UFunction_ABatteryPickup_WasCollected_Implementation, "WasCollected_Implementation" }, // 2764971762
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABatteryPickup>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABatteryPickup_Statics::NewProp_batteryPower = { "batteryPower", nullptr, (EPropertyFlags)0x0040000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryPickup, batteryPower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_batteryPower_MetaData), NewProp_batteryPower_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABatteryPickup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryPickup_Statics::NewProp_batteryPower,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryPickup_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABatteryPickup_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APickupActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BatteryCollector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryPickup_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABatteryPickup_Statics::ClassParams = {
	&ABatteryPickup::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABatteryPickup_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryPickup_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryPickup_Statics::Class_MetaDataParams), Z_Construct_UClass_ABatteryPickup_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABatteryPickup()
{
	if (!Z_Registration_Info_UClass_ABatteryPickup.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABatteryPickup.OuterSingleton, Z_Construct_UClass_ABatteryPickup_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABatteryPickup.OuterSingleton;
}
template<> BATTERYCOLLECTOR_API UClass* StaticClass<ABatteryPickup>()
{
	return ABatteryPickup::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABatteryPickup);
ABatteryPickup::~ABatteryPickup() {}
// End Class ABatteryPickup

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABatteryPickup, ABatteryPickup::StaticClass, TEXT("ABatteryPickup"), &Z_Registration_Info_UClass_ABatteryPickup, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABatteryPickup), 345417122U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_134924997(TEXT("/Script/BatteryCollector"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
