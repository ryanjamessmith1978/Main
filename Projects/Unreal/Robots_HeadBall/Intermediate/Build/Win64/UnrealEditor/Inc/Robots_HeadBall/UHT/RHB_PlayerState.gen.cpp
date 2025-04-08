// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robots_HeadBall/Public/RHB_PlayerState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRHB_PlayerState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_PlayerState();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_PlayerState_NoRegister();
UPackage* Z_Construct_UPackage__Script_Robots_HeadBall();
// End Cross Module References

// Begin Class ARHB_PlayerState
void ARHB_PlayerState::StaticRegisterNativesARHB_PlayerState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARHB_PlayerState);
UClass* Z_Construct_UClass_ARHB_PlayerState_NoRegister()
{
	return ARHB_PlayerState::StaticClass();
}
struct Z_Construct_UClass_ARHB_PlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RHB_PlayerState.h" },
		{ "ModuleRelativePath", "Public/RHB_PlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARHB_PlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARHB_PlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_Robots_HeadBall,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_PlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARHB_PlayerState_Statics::ClassParams = {
	&ARHB_PlayerState::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_PlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_ARHB_PlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARHB_PlayerState()
{
	if (!Z_Registration_Info_UClass_ARHB_PlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARHB_PlayerState.OuterSingleton, Z_Construct_UClass_ARHB_PlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARHB_PlayerState.OuterSingleton;
}
template<> ROBOTS_HEADBALL_API UClass* StaticClass<ARHB_PlayerState>()
{
	return ARHB_PlayerState::StaticClass();
}
ARHB_PlayerState::ARHB_PlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARHB_PlayerState);
ARHB_PlayerState::~ARHB_PlayerState() {}
// End Class ARHB_PlayerState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARHB_PlayerState, ARHB_PlayerState::StaticClass, TEXT("ARHB_PlayerState"), &Z_Registration_Info_UClass_ARHB_PlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARHB_PlayerState), 3619254766U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_4179187643(TEXT("/Script/Robots_HeadBall"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
