// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class Robot_HeadBallServerTarget : TargetRules
{
    public Robot_HeadBallServerTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("Robot_HeadBall");
		bUseChecksInShipping = true;
	}
}
