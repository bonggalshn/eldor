#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EldorGameInstance.generated.h"

/**
 * EGameMode
 * Represents the current game state/mode
 */
UENUM(BlueprintType)
enum class EGameMode : uint8
{
    MainMenu     UMETA(DisplayName = "Main Menu"),
    Playing      UMETA(DisplayName = "Playing"),
    Paused       UMETA(DisplayName = "Paused")
};

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

    UFUNCTION()
    void RequestExit();

    UFUNCTION()
    bool IsExiting() const { return bIsExiting; }

    UFUNCTION()
    void HandleWindowClose();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    EGameMode GetCurrentGameMode() const { return CurrentGameMode; }

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void SetCurrentGameMode(EGameMode NewMode);

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void InitializeGameState();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    bool IsInMainMenu() const { return CurrentGameMode == EGameMode::MainMenu; }

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    bool IsPlaying() const { return CurrentGameMode == EGameMode::Playing; }

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    bool IsPaused() const { return CurrentGameMode == EGameMode::Paused; }

private:
    void InitializeLogging();
    void TrackStartupTime();

    bool bIsExiting = false;
    double InitializationStartTime = 0.0;

    UPROPERTY()
    TEnumAsByte<EGameMode> CurrentGameMode;
};