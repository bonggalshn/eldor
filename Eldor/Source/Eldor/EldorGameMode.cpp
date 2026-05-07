#include "EldorGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "TitleScreenWidget.h"

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
    
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0))
    {
        if (UClass* WidgetClass = LoadClass<UTitleScreenWidget>(nullptr, TEXT("/Game/UI/W_TitleScreen.W_TitleScreen_C")))
        {
            if (UUserWidget* TitleScreen = CreateWidget<UUserWidget>(PC, WidgetClass))
            {
                TitleScreen->AddToViewport(100);
                UE_LOG(LogEldorGame, Log, TEXT("Title screen widget created and added to viewport"));
            }
            else
            {
                UE_LOG(LogEldorGame, Error, TEXT("Failed to create title screen widget"));
            }
        }
        else
        {
            UE_LOG(LogEldorGame, Warning, TEXT("Title screen UMG widget not found - using fallback C++ implementation"));
            CreateFallbackTitleScreen(PC);
        }
    }
    else
    {
        UE_LOG(LogEldorGame, Error, TEXT("Failed to get player controller for title screen"));
    }
}

void AEldorGameMode::CreateFallbackTitleScreen(APlayerController* PC)
{
    UE_LOG(LogEldorGame, Log, TEXT("Creating fallback title screen from C++"));
    
    if (UUserWidget* TitleScreen = CreateWidget<UUserWidget>(PC, UUserWidget::StaticClass()))
    {
        TitleScreen->AddToViewport(100);
        UE_LOG(LogEldorGame, Log, TEXT("Fallback title screen created (placeholder)"));
    }
}