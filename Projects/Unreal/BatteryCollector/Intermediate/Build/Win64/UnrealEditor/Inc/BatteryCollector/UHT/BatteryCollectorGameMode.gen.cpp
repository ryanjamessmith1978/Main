// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BatteryCollector/BatteryCollectorGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBatteryCollectorGameMode() {}

// Begin Cross Module References
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ABatteryCollectorGameMode();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ABatteryCollectorGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_BatteryCollector();
// End Cross Module References

// Begin Class ABatteryCollectorGameMode
void ABatteryCollectorGameMode::StaticRegisterNativesABatteryCollectorGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABatteryCollectorGameMode);
UClass* Z_Construct_UClass_ABatteryCollectorGameMode_NoRegister()
{
	return ABatteryCollectorGameMode::StaticClass();
}
struct Z_Construct_UClass_ABatteryCollectorGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "BatteryCollectorGameMode.h" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABatteryCollectorGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABatteryCollectorGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_BatteryCollector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryCollectorGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::ClassParams = {
	&ABatteryCollectorGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryCollectorGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ABatteryCollectorGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABatteryCollectorGameMode()
{
	if (!Z_Registration_Info_UClass_ABatteryCollectorGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABatteryCollectorGameMode.OuterSingleton, Z_Construct_UClass_ABatteryCollectorGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABatteryCollectorGameMode.OuterSingleton;
}
template<> BATTERYCOLLECTOR_API UClass* StaticClass<ABatteryCollectorGameMode>()
{
	return ABatteryCollectorGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABatteryCollectorGameMode);
ABatteryCollectorGameMode::~ABatteryCollectorGameMode() {}
// End Class ABatteryCollectorGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABatteryCollectorGameMode, ABatteryCollectorGameMode::StaticClass, TEXT("ABatteryCollectorGameMode"), &Z_Registration_Info_UClass_ABatteryCollectorGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABatteryCollectorGameMode), 1114463479U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_2185261384(TEXT("/Script/BatteryCollector"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
