// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class DecaMoveSDKLibrary : ModuleRules
{
	public DecaMoveSDKLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		Type = ModuleType.External;
		bEnableExceptions = true;
		// Add include

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects"
			}
		);
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicDelayLoadDLLs.Add("deca_move.dll");
			RuntimeDependencies.Add("$(PluginDir)/Binaries/Win64/deca_sdk.dll", Path.Combine(ModuleDirectory, "bin", "deca_sdk.dll"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "deca_sdk.lib"));
		}
        else if(Target.Platform == UnrealTargetPlatform.Android)
        {
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			string AndroidPluginUPL = Path.Combine(PluginPath, "DecaMove.xml");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", AndroidPluginUPL);

			string libDir = Path.Combine(ModuleDirectory, "android");
			PublicAdditionalLibraries.Add(Path.Combine(libDir, "libdeca_sdk.so"));
			PublicAdditionalLibraries.Add(Path.Combine(libDir, "libzmq.so"));
		}
		
	}
}
