// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestPluginProject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TestPluginProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TestPluginProject()
	{
		if (!Z_Registration_Info_UPackage__Script_TestPluginProject.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/TestPluginProject",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x33E91A97,
				0x6FDF94B6,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TestPluginProject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_TestPluginProject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TestPluginProject(Z_Construct_UPackage__Script_TestPluginProject, TEXT("/Script/TestPluginProject"), Z_Registration_Info_UPackage__Script_TestPluginProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x33E91A97, 0x6FDF94B6));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
