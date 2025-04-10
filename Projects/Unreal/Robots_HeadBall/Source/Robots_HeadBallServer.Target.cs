// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class Robots_HeadBallServerTarget : TargetRules
{
    public Robots_HeadBallServerTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("Robots_HeadBall");
		bUseChecksInShipping = true;
	}
}
