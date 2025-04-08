// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RHB_PlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ROBOTS_HEADBALL_RHB_PlayerController_generated_h
#error "RHB_PlayerController.generated.h already included, missing '#pragma once' in RHB_PlayerController.h"
#endif
#define ROBOTS_HEADBALL_RHB_PlayerController_generated_h

#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARHB_PlayerController(); \
	friend struct Z_Construct_UClass_ARHB_PlayerController_Statics; \
public: \
	DECLARE_CLASS(ARHB_PlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Robots_HeadBall"), NO_API) \
	DECLARE_SERIALIZER(ARHB_PlayerController)


#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARHB_PlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARHB_PlayerController(ARHB_PlayerController&&); \
	ARHB_PlayerController(const ARHB_PlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARHB_PlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARHB_PlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARHB_PlayerController) \
	NO_API virtual ~ARHB_PlayerController();


#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_12_PROLOG
#define FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ROBOTS_HEADBALL_API UClass* StaticClass<class ARHB_PlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Main_Projects_Unreal_Robots_HeadBall_Source_Robots_HeadBall_Public_RHB_PlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
