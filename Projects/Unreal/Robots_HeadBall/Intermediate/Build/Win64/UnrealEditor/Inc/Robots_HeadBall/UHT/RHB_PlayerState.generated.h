// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RHB_PlayerState.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ROBOTS_HEADBALL_RHB_PlayerState_generated_h
#error "RHB_PlayerState.generated.h already included, missing '#pragma once' in RHB_PlayerState.h"
#endif
#define ROBOTS_HEADBALL_RHB_PlayerState_generated_h

#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARHB_PlayerState(); \
	friend struct Z_Construct_UClass_ARHB_PlayerState_Statics; \
public: \
	DECLARE_CLASS(ARHB_PlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Robots_HeadBall"), NO_API) \
	DECLARE_SERIALIZER(ARHB_PlayerState)


#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARHB_PlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARHB_PlayerState(ARHB_PlayerState&&); \
	ARHB_PlayerState(const ARHB_PlayerState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARHB_PlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARHB_PlayerState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARHB_PlayerState) \
	NO_API virtual ~ARHB_PlayerState();


#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_12_PROLOG
#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_15_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ROBOTS_HEADBALL_API UClass* StaticClass<class ARHB_PlayerState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
