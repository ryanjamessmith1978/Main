// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TestPlugin/Public/TestPluginInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestPluginInterface() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
TESTPLUGIN_API UClass* Z_Construct_UClass_UTestPluginInterface();
TESTPLUGIN_API UClass* Z_Construct_UClass_UTestPluginInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_TestPlugin();
// End Cross Module References

// Begin Interface UTestPluginInterface Function TestFunction
void ITestPluginInterface::TestFunction()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_TestFunction instead.");
}
static FName NAME_UTestPluginInterface_TestFunction = FName(TEXT("TestFunction"));
void ITestPluginInterface::Execute_TestFunction(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UTestPluginInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UTestPluginInterface_TestFunction);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
}
struct Z_Construct_UFunction_UTestPluginInterface_TestFunction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/TestPluginInterface.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTestPluginInterface_TestFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTestPluginInterface, nullptr, "TestFunction", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTestPluginInterface_TestFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTestPluginInterface_TestFunction_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UTestPluginInterface_TestFunction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTestPluginInterface_TestFunction_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Interface UTestPluginInterface Function TestFunction

// Begin Interface UTestPluginInterface
void UTestPluginInterface::StaticRegisterNativesUTestPluginInterface()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTestPluginInterface);
UClass* Z_Construct_UClass_UTestPluginInterface_NoRegister()
{
	return UTestPluginInterface::StaticClass();
}
struct Z_Construct_UClass_UTestPluginInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/TestPluginInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTestPluginInterface_TestFunction, "TestFunction" }, // 2769423090
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ITestPluginInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UTestPluginInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_TestPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTestPluginInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTestPluginInterface_Statics::ClassParams = {
	&UTestPluginInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTestPluginInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UTestPluginInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTestPluginInterface()
{
	if (!Z_Registration_Info_UClass_UTestPluginInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTestPluginInterface.OuterSingleton, Z_Construct_UClass_UTestPluginInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTestPluginInterface.OuterSingleton;
}
template<> TESTPLUGIN_API UClass* StaticClass<UTestPluginInterface>()
{
	return UTestPluginInterface::StaticClass();
}
UTestPluginInterface::UTestPluginInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTestPluginInterface);
UTestPluginInterface::~UTestPluginInterface() {}
// End Interface UTestPluginInterface

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTestPluginInterface, UTestPluginInterface::StaticClass, TEXT("UTestPluginInterface"), &Z_Registration_Info_UClass_UTestPluginInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTestPluginInterface), 1330490909U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_3993498237(TEXT("/Script/TestPlugin"),
	Z_CompiledInDeferFile_FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
