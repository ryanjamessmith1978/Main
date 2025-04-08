// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Robots_HeadBall : ModuleRules
{
	public Robots_HeadBall(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
