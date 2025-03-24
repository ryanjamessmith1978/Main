// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Robot_HeadBall : ModuleRules
{
	public Robot_HeadBall(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
