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

// Begin Class ABatteryPickup
void ABatteryPickup::StaticRegisterNativesABatteryPickup()
{
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BatteryPickup.h" },
		{ "ModuleRelativePath", "Public/BatteryPickup.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABatteryPickup>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_ABatteryPickup, ABatteryPickup::StaticClass, TEXT("ABatteryPickup"), &Z_Registration_Info_UClass_ABatteryPickup, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABatteryPickup), 2167131497U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_1215957384(TEXT("/Script/BatteryCollector"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
