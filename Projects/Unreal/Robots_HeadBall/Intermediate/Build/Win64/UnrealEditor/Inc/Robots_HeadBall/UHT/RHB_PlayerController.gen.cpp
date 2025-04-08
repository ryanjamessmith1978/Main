// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robots_HeadBall/Public/RHB_PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRHB_PlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_PlayerController();
ROBOTS_HEADBALL_API UClass* Z_Construct_UClass_ARHB_PlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_Robots_HeadBall();
// End Cross Module References

// Begin Class ARHB_PlayerController
void ARHB_PlayerController::StaticRegisterNativesARHB_PlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARHB_PlayerController);
UClass* Z_Construct_UClass_ARHB_PlayerController_NoRegister()
{
	return ARHB_PlayerController::StaticClass();
}
struct Z_Construct_UClass_ARHB_PlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "RHB_PlayerController.h" },
		{ "ModuleRelativePath", "Public/RHB_PlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARHB_PlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARHB_PlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Robots_HeadBall,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_PlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARHB_PlayerController_Statics::ClassParams = {
	&ARHB_PlayerController::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARHB_PlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ARHB_PlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARHB_PlayerController()
{
	if (!Z_Registration_Info_UClass_ARHB_PlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARHB_PlayerController.OuterSingleton, Z_Construct_UClass_ARHB_PlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARHB_PlayerController.OuterSingleton;
}
template<> ROBOTS_HEADBALL_API UClass* StaticClass<ARHB_PlayerController>()
{
	return ARHB_PlayerController::StaticClass();
}
ARHB_PlayerController::ARHB_PlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARHB_PlayerController);
ARHB_PlayerController::~ARHB_PlayerController() {}
// End Class ARHB_PlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARHB_PlayerController, ARHB_PlayerController::StaticClass, TEXT("ARHB_PlayerController"), &Z_Registration_Info_UClass_ARHB_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARHB_PlayerController), 386472836U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_2338924772(TEXT("/Script/Robots_HeadBall"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
