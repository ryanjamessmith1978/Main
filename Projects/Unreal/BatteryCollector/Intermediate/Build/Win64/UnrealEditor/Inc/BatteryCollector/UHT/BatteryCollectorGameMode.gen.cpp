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
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ABatteryCollectorCharacter_NoRegister();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ABatteryCollectorGameMode();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_ABatteryCollectorGameMode_NoRegister();
BATTERYCOLLECTOR_API UEnum* Z_Construct_UEnum_BatteryCollector_EPlayState();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_BatteryCollector();
// End Cross Module References

// Begin Enum EPlayState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlayState;
static UEnum* EPlayState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlayState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlayState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_BatteryCollector_EPlayState, (UObject*)Z_Construct_UPackage__Script_BatteryCollector(), TEXT("EPlayState"));
	}
	return Z_Registration_Info_UEnum_EPlayState.OuterSingleton;
}
template<> BATTERYCOLLECTOR_API UEnum* StaticEnum<EPlayState>()
{
	return EPlayState_StaticEnum();
}
struct Z_Construct_UEnum_BatteryCollector_EPlayState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ELost.Name", "EPlayState::ELost" },
		{ "EPlaying.Name", "EPlayState::EPlaying" },
		{ "EUnknown.Name", "EPlayState::EUnknown" },
		{ "EWon.Name", "EPlayState::EWon" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlayState::EPlaying", (int64)EPlayState::EPlaying },
		{ "EPlayState::EWon", (int64)EPlayState::EWon },
		{ "EPlayState::ELost", (int64)EPlayState::ELost },
		{ "EPlayState::EUnknown", (int64)EPlayState::EUnknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_BatteryCollector_EPlayState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_BatteryCollector,
	nullptr,
	"EPlayState",
	"EPlayState",
	Z_Construct_UEnum_BatteryCollector_EPlayState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_BatteryCollector_EPlayState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_BatteryCollector_EPlayState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_BatteryCollector_EPlayState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_BatteryCollector_EPlayState()
{
	if (!Z_Registration_Info_UEnum_EPlayState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlayState.InnerSingleton, Z_Construct_UEnum_BatteryCollector_EPlayState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlayState.InnerSingleton;
}
// End Enum EPlayState

// Begin Class ABatteryCollectorGameMode Function GetCharacter
struct Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics
{
	struct BatteryCollectorGameMode_eventGetCharacter_Parms
	{
		ABatteryCollectorCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BatteryCollectorGameMode_eventGetCharacter_Parms, ReturnValue), Z_Construct_UClass_ABatteryCollectorCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABatteryCollectorGameMode, nullptr, "GetCharacter", nullptr, nullptr, Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::BatteryCollectorGameMode_eventGetCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::BatteryCollectorGameMode_eventGetCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABatteryCollectorGameMode::execGetCharacter)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ABatteryCollectorCharacter**)Z_Param__Result=P_THIS->GetCharacter();
	P_NATIVE_END;
}
// End Class ABatteryCollectorGameMode Function GetCharacter

// Begin Class ABatteryCollectorGameMode
void ABatteryCollectorGameMode::StaticRegisterNativesABatteryCollectorGameMode()
{
	UClass* Class = ABatteryCollectorGameMode::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCharacter", &ABatteryCollectorGameMode::execGetCharacter },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainHUDClass_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mainHUD_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "HUD" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_decayRate_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_myCharacter_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_myController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_currentPlayState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_powerToWin_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Power" },
		{ "ModuleRelativePath", "BatteryCollectorGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainHUDClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mainHUD;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_decayRate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_myCharacter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_myController;
	static const UECodeGen_Private::FBytePropertyParams NewProp_currentPlayState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_currentPlayState;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_powerToWin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABatteryCollectorGameMode_GetCharacter, "GetCharacter" }, // 658455259
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABatteryCollectorGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_MainHUDClass = { "MainHUDClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryCollectorGameMode, MainHUDClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainHUDClass_MetaData), NewProp_MainHUDClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_mainHUD = { "mainHUD", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryCollectorGameMode, mainHUD), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mainHUD_MetaData), NewProp_mainHUD_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_decayRate = { "decayRate", nullptr, (EPropertyFlags)0x0020080000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryCollectorGameMode, decayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_decayRate_MetaData), NewProp_decayRate_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_myCharacter = { "myCharacter", nullptr, (EPropertyFlags)0x0040000000020005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryCollectorGameMode, myCharacter), Z_Construct_UClass_ABatteryCollectorCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_myCharacter_MetaData), NewProp_myCharacter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_myController = { "myController", nullptr, (EPropertyFlags)0x0040000000020005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryCollectorGameMode, myController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_myController_MetaData), NewProp_myController_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_currentPlayState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_currentPlayState = { "currentPlayState", nullptr, (EPropertyFlags)0x0040000000020005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryCollectorGameMode, currentPlayState), Z_Construct_UEnum_BatteryCollector_EPlayState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_currentPlayState_MetaData), NewProp_currentPlayState_MetaData) }; // 1207159493
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_powerToWin = { "powerToWin", nullptr, (EPropertyFlags)0x0040000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABatteryCollectorGameMode, powerToWin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_powerToWin_MetaData), NewProp_powerToWin_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABatteryCollectorGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_MainHUDClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_mainHUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_decayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_myCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_myController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_currentPlayState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_currentPlayState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABatteryCollectorGameMode_Statics::NewProp_powerToWin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryCollectorGameMode_Statics::PropPointers) < 2048);
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
	FuncInfo,
	Z_Construct_UClass_ABatteryCollectorGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryCollectorGameMode_Statics::PropPointers),
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
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlayState_StaticEnum, TEXT("EPlayState"), &Z_Registration_Info_UEnum_EPlayState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1207159493U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABatteryCollectorGameMode, ABatteryCollectorGameMode::StaticClass, TEXT("ABatteryCollectorGameMode"), &Z_Registration_Info_UClass_ABatteryCollectorGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABatteryCollectorGameMode), 58567703U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_434103768(TEXT("/Script/BatteryCollector"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
