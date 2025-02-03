// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TestPluginInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TESTPLUGIN_TestPluginInterface_generated_h
#error "TestPluginInterface.generated.h already included, missing '#pragma once' in TestPluginInterface.h"
#endif
#define TESTPLUGIN_TestPluginInterface_generated_h

#define FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_CALLBACK_WRAPPERS
#define FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TESTPLUGIN_API UTestPluginInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UTestPluginInterface(UTestPluginInterface&&); \
	UTestPluginInterface(const UTestPluginInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TESTPLUGIN_API, UTestPluginInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTestPluginInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTestPluginInterface) \
	TESTPLUGIN_API virtual ~UTestPluginInterface();


#define FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUTestPluginInterface(); \
	friend struct Z_Construct_UClass_UTestPluginInterface_Statics; \
public: \
	DECLARE_CLASS(UTestPluginInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/TestPlugin"), TESTPLUGIN_API) \
	DECLARE_SERIALIZER(UTestPluginInterface)


#define FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ITestPluginInterface() {} \
public: \
	typedef UTestPluginInterface UClassType; \
	typedef ITestPluginInterface ThisClass; \
	static void Execute_TestFunction(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_10_PROLOG
#define FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_CALLBACK_WRAPPERS \
	FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TESTPLUGIN_API UClass* StaticClass<class UTestPluginInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_RySmi_Source_Main_Projects_Unreal_TestPluginProject_Plugins_TestPlugin_Source_TestPlugin_Public_TestPluginInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
