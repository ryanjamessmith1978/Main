using UnrealBuildTool;
using System.Collections.Generic;

public class Robot_HeadBallClientTarget : TargetRules
{
    public Robot_HeadBallClientTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Client;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("Robot_HeadBall");
		bUseChecksInShipping = true;
	}
}