// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robots_HeadBall/Public/RHB_GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRHB_GameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_GameMode();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_GameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Robots_HeadBall();
// End Cross Module References

// Begin Class ARHB_GameMode
void ARHB_GameMode::StaticRegisterNativesARHB_GameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARHB_GameMode);
UClass* Z_Construct_UClass_ARHB_GameMode_NoRegister()
{
	return ARHB_GameMode::StaticClass();
}
struct Z_Construct_UClass_ARHB_GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RHB_GameMode.h" },
		{ "ModuleRelativePath", "Public/RHB_GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARHB_GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARHB_GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Robots_HeadBall,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARHB_GameMode_Statics::ClassParams = {
	&ARHB_GameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ARHB_GameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARHB_GameMode()
{
	if (!Z_Registration_Info_UClass_ARHB_GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARHB_GameMode.OuterSingleton, Z_Construct_UClass_ARHB_GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARHB_GameMode.OuterSingleton;
}
template<> ROBOTS_HEADBALL_API UClass* StaticClass<ARHB_GameMode>()
{
	return ARHB_GameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARHB_GameMode);
ARHB_GameMode::~ARHB_GameMode() {}
// End Class ARHB_GameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARHB_GameMode, ARHB_GameMode::StaticClass, TEXT("ARHB_GameMode"), &Z_Registration_Info_UClass_ARHB_GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARHB_GameMode), 3871623256U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_157786470(TEXT("/Script/Robots_HeadBall"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
