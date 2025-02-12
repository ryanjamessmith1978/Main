// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BatteryPickup.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTERYCOLLECTOR_BatteryPickup_generated_h
#error "BatteryPickup.generated.h already included, missing '#pragma once' in BatteryPickup.h"
#endif
#define BATTERYCOLLECTOR_BatteryPickup_generated_h

#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABatteryPickup(); \
	friend struct Z_Construct_UClass_ABatteryPickup_Statics; \
public: \
	DECLARE_CLASS(ABatteryPickup, APickupActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(ABatteryPickup)


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABatteryPickup(ABatteryPickup&&); \
	ABatteryPickup(const ABatteryPickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryPickup); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryPickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABatteryPickup) \
	NO_API virtual ~ABatteryPickup();


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_12_PROLOG
#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_15_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BATTERYCOLLECTOR_API UClass* StaticClass<class ABatteryPickup>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_BatteryPickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
