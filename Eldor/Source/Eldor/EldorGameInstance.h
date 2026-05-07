#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EldorGameInstance.generated.h"

/**
 * EldorGameInstance
 * Manages application lifecycle and global game state
 * Handles initialization, shutdown, and cross-level data
 */
UCLASS()
class ELDOR_API UEldorGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UEldorGameInstance();

    virtual void Init() override;
    virtual void Shutdown() override;
    virtual bool JoinSession(ULocalPlayer* Player, const FString& SessionName) override;
    virtual void HandleDemoPlay() override;

    void RequestExit();
    bool IsExiting() const { return bIsExiting; }
    void HandleWindowClose();

private:
    void InitializeLogging();
    void TrackStartupTime();

    bool bIsExiting;
    double InitializationStartTime;
};

#if !defined(ELDOR_GAMEINSTANCE_API)
#define ELDOR_GAMEINSTANCE_API DLLEXPORT
#endif