#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EldorGameMode.generated.h"

class APlayerController;

/**
 * EldorGameMode
 * Main game mode for Eldor RPG title screen
 * Handles game initialization and UI presentation
 */
UCLASS()
class ELDOR_API AEldorGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AEldorGameMode();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    void ShowTitleScreen();
    void InitializeLogging();
    void CreateFallbackTitleScreen(APlayerController* PC);
};