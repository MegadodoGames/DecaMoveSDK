// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class DecaMoveSDKLibrary : ModuleRules
{
	public DecaMoveSDKLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		bEnableExceptions = true;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add include
			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

			// Add the import library
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "release", "deca_sdk.dll"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("deca_move.dll");

			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(PluginDir)/Binaries/Win64/deca_sdk.dll", Path.Combine(ModuleDirectory, "bin", "deca_sdk.dll"));
			 
			// Load .lib
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "deca_sdk.lib"));
		}
	}
}
