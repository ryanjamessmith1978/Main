// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RHB_GameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ROBOTS_HEADBALL_RHB_GameMode_generated_h
#error "RHB_GameMode.generated.h already included, missing '#pragma once' in RHB_GameMode.h"
#endif
#define ROBOTS_HEADBALL_RHB_GameMode_generated_h

#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARHB_GameMode(); \
	friend struct Z_Construct_UClass_ARHB_GameMode_Statics; \
public: \
	DECLARE_CLASS(ARHB_GameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Robots_HeadBall"), ROBOTS_HEADBALL_API) \
	DECLARE_SERIALIZER(ARHB_GameMode)


#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARHB_GameMode(ARHB_GameMode&&); \
	ARHB_GameMode(const ARHB_GameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ROBOTS_HEADBALL_API, ARHB_GameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARHB_GameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARHB_GameMode) \
	ROBOTS_HEADBALL_API virtual ~ARHB_GameMode();


#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_9_PROLOG
#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_13_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ROBOTS_HEADBALL_API UClass* StaticClass<class ARHB_GameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_GameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
