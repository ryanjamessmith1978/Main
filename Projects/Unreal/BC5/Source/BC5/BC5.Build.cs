// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BC5 : ModuleRules
{
	public BC5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
