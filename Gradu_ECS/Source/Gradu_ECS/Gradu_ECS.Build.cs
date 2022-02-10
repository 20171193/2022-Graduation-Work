// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Gradu_ECS : ModuleRules
{
	public Gradu_ECS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
