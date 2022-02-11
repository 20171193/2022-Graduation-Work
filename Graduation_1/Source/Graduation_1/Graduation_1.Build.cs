// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Graduation_1 : ModuleRules
{
	public Graduation_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
