// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BatteryCollector/Public/SpawnVolume.h"
#include "Runtime/Engine/Classes/Engine/TimerHandle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpawnVolume() {}

// Begin Cross Module References
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_APickupActor_NoRegister();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ASpawnVolume();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ASpawnVolume_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
UPackage* Z_Construct_UPackage__Script_BatteryCollector();
// End Cross Module References

// Begin Class ASpawnVolume Function SpawnPickup
struct Z_Construct_UFunction_ASpawnVolume_SpawnPickup_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpawnVolume_SpawnPickup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpawnVolume, nullptr, "SpawnPickup", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_SpawnPickup_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpawnVolume_SpawnPickup_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASpawnVolume_SpawnPickup()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpawnVolume_SpawnPickup_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpawnVolume::execSpawnPickup)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnPickup();
	P_NATIVE_END;
}
// End Class ASpawnVolume Function SpawnPickup

// Begin Class ASpawnVolume
void ASpawnVolume::StaticRegisterNativesASpawnVolume()
{
	UClass* Class = ASpawnVolume::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SpawnPickup", &ASpawnVolume::execSpawnPickup },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpawnVolume);
UClass* Z_Construct_UClass_ASpawnVolume_NoRegister()
{
	return ASpawnVolume::StaticClass();
}
struct Z_Construct_UClass_ASpawnVolume_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SpawnVolume.h" },
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimerHandle_MetaData[] = {
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spawnVolume_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "Spawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_pickup_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spawnLowTime_MetaData[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spawnHighTime_MetaData[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spawnTime_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/SpawnVolume.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TimerHandle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_spawnVolume;
	static const UECodeGen_Private::FClassPropertyParams NewProp_pickup;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_spawnLowTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_spawnHighTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_spawnTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpawnVolume_SpawnPickup, "SpawnPickup" }, // 3284346287
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpawnVolume>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_TimerHandle = { "TimerHandle", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, TimerHandle), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimerHandle_MetaData), NewProp_TimerHandle_MetaData) }; // 756291145
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnVolume = { "spawnVolume", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, spawnVolume), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spawnVolume_MetaData), NewProp_spawnVolume_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_pickup = { "pickup", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, pickup), Z_Construct_UClass_UClass, Z_Construct_UClass_APickupActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_pickup_MetaData), NewProp_pickup_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnLowTime = { "spawnLowTime", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, spawnLowTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spawnLowTime_MetaData), NewProp_spawnLowTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnHighTime = { "spawnHighTime", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, spawnHighTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spawnHighTime_MetaData), NewProp_spawnHighTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnTime = { "spawnTime", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawnVolume, spawnTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spawnTime_MetaData), NewProp_spawnTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpawnVolume_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_TimerHandle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_pickup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnLowTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnHighTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_spawnTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpawnVolume_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BatteryCollector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpawnVolume_Statics::ClassParams = {
	&ASpawnVolume::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASpawnVolume_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpawnVolume_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpawnVolume()
{
	if (!Z_Registration_Info_UClass_ASpawnVolume.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpawnVolume.OuterSingleton, Z_Construct_UClass_ASpawnVolume_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpawnVolume.OuterSingleton;
}
template<> BATTERYCOLLECTOR_API UClass* StaticClass<ASpawnVolume>()
{
	return ASpawnVolume::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpawnVolume);
ASpawnVolume::~ASpawnVolume() {}
// End Class ASpawnVolume

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpawnVolume, ASpawnVolume::StaticClass, TEXT("ASpawnVolume"), &Z_Registration_Info_UClass_ASpawnVolume, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpawnVolume), 1608929006U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_3757826801(TEXT("/Script/BatteryCollector"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
