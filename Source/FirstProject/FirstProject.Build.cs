// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FirstProject : ModuleRules
{
	public FirstProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		// UMG : Unreal Motion Graphics (HUD�� ����� ���ؼ�)
		// AIModule : AI
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "AIModule" });

		// Slate UI (HUD ���� �ý���)
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
