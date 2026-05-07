#include "EldorGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"

AEldorGameMode::AEldorGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AEldorGameMode::BeginPlay()
{
    Super::BeginPlay();
    InitializeLogging();
    ShowTitleScreen();
}

void AEldorGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    UE_LOG(LogEldorGame, Log, TEXT("EldorGameMode EndPlay: %d"), (int32)EndPlayReason);
    Super::EndPlay(EndPlayReason);
}

void AEldorGameMode::InitializeLogging()
{
    double StartTime = FPlatformTime::Seconds();
    UE_LOG(LogEldorGame, Log, TEXT("=== ELDOR GAME STARTED ==="));
    UE_LOG(LogEldorGame, Log, TEXT("GameMode initialized at %.3f seconds"), StartTime);
}

void AEldorGameMode::ShowTitleScreen()
{
    UE_LOG(LogEldorGame, Log, TEXT("Loading title screen..."));
    // Title screen widget creation will be handled in Phase 3
}