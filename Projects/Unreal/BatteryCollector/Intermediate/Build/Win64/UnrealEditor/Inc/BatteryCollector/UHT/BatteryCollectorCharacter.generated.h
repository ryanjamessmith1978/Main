// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BatteryCollectorCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTERYCOLLECTOR_BatteryCollectorCharacter_generated_h
#error "BatteryCollectorCharacter.generated.h already included, missing '#pragma once' in BatteryCollectorCharacter.h"
#endif
#define BATTERYCOLLECTOR_BatteryCollectorCharacter_generated_h

#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCollectPickups);


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABatteryCollectorCharacter(); \
	friend struct Z_Construct_UClass_ABatteryCollectorCharacter_Statics; \
public: \
	DECLARE_CLASS(ABatteryCollectorCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(ABatteryCollectorCharacter)


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABatteryCollectorCharacter(ABatteryCollectorCharacter&&); \
	ABatteryCollectorCharacter(const ABatteryCollectorCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryCollectorCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryCollectorCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABatteryCollectorCharacter) \
	NO_API virtual ~ABatteryCollectorCharacter();


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_19_PROLOG
#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_22_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BATTERYCOLLECTOR_API UClass* StaticClass<class ABatteryCollectorCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
