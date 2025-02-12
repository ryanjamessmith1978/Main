// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PickupActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMeshComponent;
#ifdef BATTERYCOLLECTOR_PickupActor_generated_h
#error "PickupActor.generated.h already included, missing '#pragma once' in PickupActor.h"
#endif
#define BATTERYCOLLECTOR_PickupActor_generated_h

#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execWasCollected); \
	DECLARE_FUNCTION(execGetMesh); \
	DECLARE_FUNCTION(execSetbIsActive); \
	DECLARE_FUNCTION(execGetbIsActive);


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_CALLBACK_WRAPPERS
#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickupActor(); \
	friend struct Z_Construct_UClass_APickupActor_Statics; \
public: \
	DECLARE_CLASS(APickupActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(APickupActor)


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APickupActor(APickupActor&&); \
	APickupActor(const APickupActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickupActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickupActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickupActor) \
	NO_API virtual ~APickupActor();


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_10_PROLOG
#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_CALLBACK_WRAPPERS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BATTERYCOLLECTOR_API UClass* StaticClass<class APickupActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_PickupActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
