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

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            }
        );
    }
}