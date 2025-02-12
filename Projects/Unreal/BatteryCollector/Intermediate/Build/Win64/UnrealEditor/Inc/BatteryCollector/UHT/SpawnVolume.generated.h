// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpawnVolume.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTERYCOLLECTOR_SpawnVolume_generated_h
#error "SpawnVolume.generated.h already included, missing '#pragma once' in SpawnVolume.h"
#endif
#define BATTERYCOLLECTOR_SpawnVolume_generated_h

#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSpawnPickup);


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpawnVolume(); \
	friend struct Z_Construct_UClass_ASpawnVolume_Statics; \
public: \
	DECLARE_CLASS(ASpawnVolume, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(ASpawnVolume)


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASpawnVolume(ASpawnVolume&&); \
	ASpawnVolume(const ASpawnVolume&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpawnVolume); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpawnVolume); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpawnVolume) \
	NO_API virtual ~ASpawnVolume();


#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_11_PROLOG
#define FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_14_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BATTERYCOLLECTOR_API UClass* StaticClass<class ASpawnVolume>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_BatteryCollector_Source_BatteryCollector_Public_SpawnVolume_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
