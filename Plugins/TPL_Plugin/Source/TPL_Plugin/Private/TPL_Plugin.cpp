// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPL_Plugin.h"
#include "Misc/MessageDialog.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "ThirdParty/TPL_PluginLibrary/TestClass.h"

#define LOCTEXT_NAMESPACE "FTPL_PluginModule"

void FTPL_PluginModule::StartupModule()
{

}

void FTPL_PluginModule::ShutdownModule()
{

}
	
IMPLEMENT_MODULE(FTPL_PluginModule, TPL_Plugin)
