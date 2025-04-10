// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Robots_HeadBallClientTarget : TargetRules
{
    public Robots_HeadBallClientTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Client;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("Robots_HeadBall");
		bUseChecksInShipping = true;
	}
}