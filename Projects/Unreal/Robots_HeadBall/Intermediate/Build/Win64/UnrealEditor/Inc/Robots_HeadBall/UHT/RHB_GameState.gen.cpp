// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robots_HeadBall/Public/RHB_GameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRHB_GameState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_GameState();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_GameState_NoRegister();
UPackage* Z_Construct_UPackage__Script_Robots_HeadBall();
// End Cross Module References

// Begin Class ARHB_GameState
void ARHB_GameState::StaticRegisterNativesARHB_GameState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARHB_GameState);
UClass* Z_Construct_UClass_ARHB_GameState_NoRegister()
{
	return ARHB_GameState::StaticClass();
}
struct Z_Construct_UClass_ARHB_GameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RHB_GameState.h" },
		{ "ModuleRelativePath", "Public/RHB_GameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARHB_GameState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARHB_GameState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameStateBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Robots_HeadBall,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_GameState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARHB_GameState_Statics::ClassParams = {
	&ARHB_GameState::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_GameState_Statics::Class_MetaDataParams), Z_Construct_UClass_ARHB_GameState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARHB_GameState()
{
	if (!Z_Registration_Info_UClass_ARHB_GameState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARHB_GameState.OuterSingleton, Z_Construct_UClass_ARHB_GameState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARHB_GameState.OuterSingleton;
}
template<> ROBOTS_HEADBALL_API UClass* StaticClass<ARHB_GameState>()
{
	return ARHB_GameState::StaticClass();
}
ARHB_GameState::ARHB_GameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARHB_GameState);
ARHB_GameState::~ARHB_GameState() {}
// End Class ARHB_GameState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARHB_GameState, ARHB_GameState::StaticClass, TEXT("ARHB_GameState"), &Z_Registration_Info_UClass_ARHB_GameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARHB_GameState), 2634897104U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameState_h_301499435(TEXT("/Script/Robots_HeadBall"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
