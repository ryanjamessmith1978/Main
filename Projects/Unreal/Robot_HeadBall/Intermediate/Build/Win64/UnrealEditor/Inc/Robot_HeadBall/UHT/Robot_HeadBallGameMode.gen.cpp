// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robot_HeadBall/Robot_HeadBallGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRobot_HeadBallGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ROBOT_HEADBALL_API UClass* Z_Construct_UClass_ARobot_HeadBallGameMode();
ROBOT_HEADBALL_API UClass* Z_Construct_UClass_ARobot_HeadBallGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Robot_HeadBall();
// End Cross Module References

// Begin Class ARobot_HeadBallGameMode
void ARobot_HeadBallGameMode::StaticRegisterNativesARobot_HeadBallGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARobot_HeadBallGameMode);
UClass* Z_Construct_UClass_ARobot_HeadBallGameMode_NoRegister()
{
	return ARobot_HeadBallGameMode::StaticClass();
}
struct Z_Construct_UClass_ARobot_HeadBallGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Robot_HeadBallGameMode.h" },
		{ "ModuleRelativePath", "Robot_HeadBallGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARobot_HeadBallGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARobot_HeadBallGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Robot_HeadBall,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARobot_HeadBallGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARobot_HeadBallGameMode_Statics::ClassParams = {
	&ARobot_HeadBallGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARobot_HeadBallGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ARobot_HeadBallGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARobot_HeadBallGameMode()
{
	if (!Z_Registration_Info_UClass_ARobot_HeadBallGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARobot_HeadBallGameMode.OuterSingleton, Z_Construct_UClass_ARobot_HeadBallGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARobot_HeadBallGameMode.OuterSingleton;
}
template<> ROBOT_HEADBALL_API UClass* StaticClass<ARobot_HeadBallGameMode>()
{
	return ARobot_HeadBallGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARobot_HeadBallGameMode);
ARobot_HeadBallGameMode::~ARobot_HeadBallGameMode() {}
// End Class ARobot_HeadBallGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robot_HeadBall_Source_Robot_HeadBall_Robot_HeadBallGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARobot_HeadBallGameMode, ARobot_HeadBallGameMode::StaticClass, TEXT("ARobot_HeadBallGameMode"), &Z_Registration_Info_UClass_ARobot_HeadBallGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARobot_HeadBallGameMode), 1042417088U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robot_HeadBall_Source_Robot_HeadBall_Robot_HeadBallGameMode_h_1280873005(TEXT("/Script/Robot_HeadBall"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robot_HeadBall_Source_Robot_HeadBall_Robot_HeadBallGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_Robot_HeadBall_Source_Robot_HeadBall_Robot_HeadBallGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
