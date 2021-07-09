// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class TestTopDown : ModuleRules
{
	public TestTopDown(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });

        // Include DecaSDK
        var DecaRoot = Path.Combine(ModuleDirectory, "..\\..\\..\\..");
        var DecaSDKDirectory = Path.Combine(DecaRoot, "build", "_package", "SDK");
		PublicIncludePaths.Add(Path.Combine(DecaSDKDirectory, "include"));
		PublicAdditionalLibraries.Add(Path.Combine(DecaSDKDirectory, "lib", "deca_sdk.lib"));
	}
}
