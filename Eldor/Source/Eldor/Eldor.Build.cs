// Eldor Build Configuration
using UnrealBuildTool;

public class Eldor : ModuleRules
{
    public Eldor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "Eldor/Public"
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
                "Eldor/Private"
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "UMG",
                "Slate",
                "SlateCore"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "RenderCore",
                "RHI"
            }
        );

        // Testing support (TDD per Constitution III)
        if (Target.bCompileAgainstEngine)
        {
            PrivateDependencyModuleNames.Add("AutomationTest");
        }

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            }
        );
    }
}