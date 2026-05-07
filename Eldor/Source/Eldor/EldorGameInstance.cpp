#include "EldorGameInstance.h"
#include "Logging/LogMacros.h"
#include "Misc/OutputDevice.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Engine/Engine.h"
#include "HAL/IPlatformInputStreamableManager.h"

UEldorGameInstance::UEldorGameInstance()
{
}

void UEldorGameInstance::Init()
{
    Super::Init();
    InitializationStartTime = FPlatformTime::Seconds();
    InitializeGameState();
    InitializeLogging();
    TrackStartupTime();
    UE_LOG(LogEldorGame, Log, TEXT("EldorGameInstance initialized successfully"));
}

void UEldorGameInstance::Shutdown()
{
    UE_LOG(LogEldorGame, Log, TEXT("EldorGameInstance shutting down..."));
    double TotalRuntime = FPlatformTime::Seconds() - InitializationStartTime;
    UE_LOG(LogEldorGame, Log, TEXT("Total runtime: %.2f seconds"), TotalRuntime);
    UE_LOG(LogEldorGame, Log, TEXT("=== ELDOR GAME SHUTDOWN COMPLETE ==="));
    Super::Shutdown();
}

bool UEldorGameInstance::JoinSession(ULocalPlayer* Player, const FString& SessionName)
{
    UE_LOG(LogEldorGame, Log, TEXT("JoinSession called: %s"), *SessionName);
    return Super::JoinSession(Player, SessionName);
}

void UEldorGameInstance::HandleDemoPlay()
{
    UE_LOG(LogEldorGame, Log, TEXT("Demo play mode initiated"));
    Super::HandleDemoPlay();
}

void UEldorGameInstance::RequestExit()
{
    if (!bIsExiting)
    {
        bIsExiting = true;
        UE_LOG(LogEldorGame, Log, TEXT("Exit requested - terminating application"));
        FPlatformProcess::RequestExit(false);
    }
}

void UEldorGameInstance::InitializeLogging()
{
    UE_LOG(LogEldorGame, Log, TEXT("=== ELDOR GAME INSTANCE CREATED ==="));
    UE_LOG(LogEldorGame, Log, TEXT("Version: 0.1.0"));
    UE_LOG(LogEldorGame, Log, TEXT("Platform: Windows"));
}

void UEldorGameInstance::TrackStartupTime()
{
    double StartupTime = FPlatformTime::Seconds() - InitializationStartTime;
    UE_LOG(LogEldorGame, Log, TEXT("Startup completed in %.3f seconds"), StartupTime);
    
    if (StartupTime <= 3.0)
    {
        UE_LOG(LogEldorGame, Log, TEXT("Startup time target met (under 3 seconds)"));
    }
    else
    {
        UE_LOG(LogEldorGame, Warning, TEXT("Startup time exceeded 3 second target: %.3f seconds"), StartupTime);
    }
}

void UEldorGameInstance::HandleWindowClose()
{
    UE_LOG(LogEldorGame, Log, TEXT("Window close event received - initiating clean shutdown"));
    RequestExit();
}

void UEldorGameInstance::SetCurrentGameMode(EGameMode NewMode)
{
    EGameMode OldMode = CurrentGameMode;
    CurrentGameMode = NewMode;

    FString OldModeStr;
    switch (OldMode)
    {
        case EGameMode::MainMenu: OldModeStr = TEXT("MainMenu"); break;
        case EGameMode::Playing: OldModeStr = TEXT("Playing"); break;
        case EGameMode::Paused: OldModeStr = TEXT("Paused"); break;
    }

    FString NewModeStr;
    switch (NewMode)
    {
        case EGameMode::MainMenu: NewModeStr = TEXT("MainMenu"); break;
        case EGameMode::Playing: NewModeStr = TEXT("Playing"); break;
        case EGameMode::Paused: NewModeStr = TEXT("Paused"); break;
    }

    UE_LOG(LogEldorGame, Log, TEXT("GameMode changed: %s -> %s"), *OldModeStr, *NewModeStr);
}

void UEldorGameInstance::InitializeGameState()
{
    CurrentGameMode = EGameMode::MainMenu;
    UE_LOG(LogEldorGame, Log, TEXT("Game state initialized to MainMenu mode"));
}