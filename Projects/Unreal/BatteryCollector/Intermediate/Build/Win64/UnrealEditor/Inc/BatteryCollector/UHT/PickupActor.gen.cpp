// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BatteryCollector/Public/PickupActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickupActor() {}

// Begin Cross Module References
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_APickupActor();
BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_APickupActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BatteryCollector();
// End Cross Module References

// Begin Class APickupActor Function GetbIsActive
struct Z_Construct_UFunction_APickupActor_GetbIsActive_Statics
{
	struct PickupActor_eventGetbIsActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pickup" },
		{ "ModuleRelativePath", "Public/PickupActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PickupActor_eventGetbIsActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PickupActor_eventGetbIsActive_Parms), &Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickupActor, nullptr, "GetbIsActive", nullptr, nullptr, Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::PropPointers), sizeof(Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::PickupActor_eventGetbIsActive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::PickupActor_eventGetbIsActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APickupActor_GetbIsActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APickupActor_GetbIsActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APickupActor::execGetbIsActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetbIsActive();
	P_NATIVE_END;
}
// End Class APickupActor Function GetbIsActive

// Begin Class APickupActor Function GetMesh
struct Z_Construct_UFunction_APickupActor_GetMesh_Statics
{
	struct PickupActor_eventGetMesh_Parms
	{
		UStaticMeshComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pickup" },
		{ "ModuleRelativePath", "Public/PickupActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APickupActor_GetMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PickupActor_eventGetMesh_Parms, ReturnValue), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APickupActor_GetMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APickupActor_GetMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_GetMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APickupActor_GetMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickupActor, nullptr, "GetMesh", nullptr, nullptr, Z_Construct_UFunction_APickupActor_GetMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_GetMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_APickupActor_GetMesh_Statics::PickupActor_eventGetMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_GetMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_APickupActor_GetMesh_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APickupActor_GetMesh_Statics::PickupActor_eventGetMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APickupActor_GetMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APickupActor_GetMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APickupActor::execGetMesh)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UStaticMeshComponent**)Z_Param__Result=P_THIS->GetMesh();
	P_NATIVE_END;
}
// End Class APickupActor Function GetMesh

// Begin Class APickupActor Function SetbIsActive
struct Z_Construct_UFunction_APickupActor_SetbIsActive_Statics
{
	struct PickupActor_eventSetbIsActive_Parms
	{
		bool act;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pickup" },
		{ "ModuleRelativePath", "Public/PickupActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_act_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_act;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::NewProp_act_SetBit(void* Obj)
{
	((PickupActor_eventSetbIsActive_Parms*)Obj)->act = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::NewProp_act = { "act", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PickupActor_eventSetbIsActive_Parms), &Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::NewProp_act_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::NewProp_act,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickupActor, nullptr, "SetbIsActive", nullptr, nullptr, Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::PropPointers), sizeof(Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::PickupActor_eventSetbIsActive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::PickupActor_eventSetbIsActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APickupActor_SetbIsActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APickupActor_SetbIsActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APickupActor::execSetbIsActive)
{
	P_GET_UBOOL(Z_Param_act);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetbIsActive(Z_Param_act);
	P_NATIVE_END;
}
// End Class APickupActor Function SetbIsActive

// Begin Class APickupActor Function WasCollected
static const FName NAME_APickupActor_WasCollected = FName(TEXT("WasCollected"));
void APickupActor::WasCollected()
{
	UFunction* Func = FindFunctionChecked(NAME_APickupActor_WasCollected);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		WasCollected_Implementation();
	}
}
struct Z_Construct_UFunction_APickupActor_WasCollected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pickup" },
		{ "ModuleRelativePath", "Public/PickupActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APickupActor_WasCollected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickupActor, nullptr, "WasCollected", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APickupActor_WasCollected_Statics::Function_MetaDataParams), Z_Construct_UFunction_APickupActor_WasCollected_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APickupActor_WasCollected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APickupActor_WasCollected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APickupActor::execWasCollected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->WasCollected_Implementation();
	P_NATIVE_END;
}
// End Class APickupActor Function WasCollected

// Begin Class APickupActor
void APickupActor::StaticRegisterNativesAPickupActor()
{
	UClass* Class = APickupActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetbIsActive", &APickupActor::execGetbIsActive },
		{ "GetMesh", &APickupActor::execGetMesh },
		{ "SetbIsActive", &APickupActor::execSetbIsActive },
		{ "WasCollected", &APickupActor::execWasCollected },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APickupActor);
UClass* Z_Construct_UClass_APickupActor_NoRegister()
{
	return APickupActor::StaticClass();
}
struct Z_Construct_UClass_APickupActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PickupActor.h" },
		{ "ModuleRelativePath", "Public/PickupActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsActive_MetaData[] = {
		{ "Category", "Pickup" },
		{ "ModuleRelativePath", "Public/PickupActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_pickupMesh_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "Pickup" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PickupActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_pickupMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APickupActor_GetbIsActive, "GetbIsActive" }, // 86868632
		{ &Z_Construct_UFunction_APickupActor_GetMesh, "GetMesh" }, // 226991985
		{ &Z_Construct_UFunction_APickupActor_SetbIsActive, "SetbIsActive" }, // 725661551
		{ &Z_Construct_UFunction_APickupActor_WasCollected, "WasCollected" }, // 1277937778
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APickupActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_APickupActor_Statics::NewProp_bIsActive_SetBit(void* Obj)
{
	((APickupActor*)Obj)->bIsActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APickupActor_Statics::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APickupActor), &Z_Construct_UClass_APickupActor_Statics::NewProp_bIsActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsActive_MetaData), NewProp_bIsActive_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APickupActor_Statics::NewProp_pickupMesh = { "pickupMesh", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APickupActor, pickupMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_pickupMesh_MetaData), NewProp_pickupMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APickupActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickupActor_Statics::NewProp_bIsActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickupActor_Statics::NewProp_pickupMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APickupActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APickupActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BatteryCollector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APickupActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APickupActor_Statics::ClassParams = {
	&APickupActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APickupActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APickupActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APickupActor_Statics::Class_MetaDataParams), Z_Construct_UClass_APickupActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APickupActor()
{
	if (!Z_Registration_Info_UClass_APickupActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APickupActor.OuterSingleton, Z_Construct_UClass_APickupActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APickupActor.OuterSingleton;
}
template<> BATTERYCOLLECTOR_API UClass* StaticClass<APickupActor>()
{
	return APickupActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APickupActor);
APickupActor::~APickupActor() {}
// End Class APickupActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APickupActor, APickupActor::StaticClass, TEXT("APickupActor"), &Z_Registration_Info_UClass_APickupActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APickupActor), 3355345800U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_4015606128(TEXT("/Script/BatteryCollector"),
	Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
