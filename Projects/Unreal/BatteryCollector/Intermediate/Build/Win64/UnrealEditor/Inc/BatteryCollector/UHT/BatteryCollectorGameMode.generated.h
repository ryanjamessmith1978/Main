// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BatteryCollectorGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTERYCOLLECTOR_BatteryCollectorGameMode_generated_h
#error "BatteryCollectorGameMode.generated.h already included, missing '#pragma once' in BatteryCollectorGameMode.h"
#endif
#define BATTERYCOLLECTOR_BatteryCollectorGameMode_generated_h

#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABatteryCollectorGameMode(); \
	friend struct Z_Construct_UClass_ABatteryCollectorGameMode_Statics; \
public: \
	DECLARE_CLASS(ABatteryCollectorGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/BatteryCollector"), BATTERYCOLLECTOR_API) \
	DECLARE_SERIALIZER(ABatteryCollectorGameMode)


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABatteryCollectorGameMode(ABatteryCollectorGameMode&&); \
	ABatteryCollectorGameMode(const ABatteryCollectorGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(BATTERYCOLLECTOR_API, ABatteryCollectorGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryCollectorGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABatteryCollectorGameMode) \
	BATTERYCOLLECTOR_API virtual ~ABatteryCollectorGameMode();


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_9_PROLOG
#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BATTERYCOLLECTOR_API UClass* StaticClass<class ABatteryCollectorGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
