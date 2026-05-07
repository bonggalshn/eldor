#include "PauseMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Logging/LogMacros.h"
#include "EldorGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

UPauseMenuWidget::UPauseMenuWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UPauseMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: NativeConstruct - Initializing pause menu"));

    BindButtons();
}

void UPauseMenuWidget::NativeDestruct()
{
    UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: NativeDestruct"));
    RestoreInputMode();
    Super::NativeDestruct();
}

void UPauseMenuWidget::ShowMenu()
{
    UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: ShowMenu - Displaying pause menu"));

    AddToViewport(1000);

    SetupInputMode();

    if (UWorld* World = GetWorld())
    {
        for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
        {
            if (APlayerController* PC = It->Get())
            {
                PC->SetPause(true);
                PC->bShowMouseCursor = true;
            }
        }
    }

    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEldorGameInstance* EldorGI = Cast<UEldorGameInstance>(GameInstance))
        {
            EldorGI->SetCurrentGameMode(EGameMode::Paused);
        }
    }
}

void UPauseMenuWidget::HideMenu()
{
    UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: HideMenu - Hiding pause menu"));

    RemoveFromParent();

    RestoreInputMode();

    if (UWorld* World = GetWorld())
    {
        for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
        {
            if (APlayerController* PC = It->Get())
            {
                PC->SetPause(false);
                PC->bShowMouseCursor = false;
            }
        }
    }

    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEldorGameInstance* EldorGI = Cast<UEldorGameInstance>(GameInstance))
        {
            EldorGI->SetCurrentGameMode(EGameMode::Playing);
        }
    }
}

void UPauseMenuWidget::OnReturnToMenuClicked()
{
    UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: Return to Menu clicked"));

    HideMenu();

    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEldorGameInstance* EldorGI = Cast<UEldorGameInstance>(GameInstance))
        {
            EldorGI->SetCurrentGameMode(EGameMode::MainMenu);
        }
    }

    UGameplayStatics::OpenLevel(this, FName(TEXT("TitleScreen")), true);
}

void UPauseMenuWidget::OnExitToDesktopClicked()
{
    UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: Exit to Desktop clicked - requesting application exit"));

    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEldorGameInstance* EldorGI = Cast<UEldorGameInstance>(GameInstance))
        {
            EldorGI->RequestExit();
        }
    }
}

void UPauseMenuWidget::BindButtons()
{
    if (ReturnToMenuButton)
    {
        ReturnToMenuButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnReturnToMenuClicked);
        UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: ReturnToMenuButton bound"));
    }
    else
    {
        UE_LOG(LogEldorGame, Warning, TEXT("PauseMenuWidget: ReturnToMenuButton binding not found"));
    }

    if (ExitToDesktopButton)
    {
        ExitToDesktopButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnExitToDesktopClicked);
        UE_LOG(LogEldorGame, Log, TEXT("PauseMenuWidget: ExitToDesktopButton bound"));
    }
    else
    {
        UE_LOG(LogEldorGame, Warning, TEXT("PauseMenuWidget: ExitToDesktopButton binding not found"));
    }
}

void UPauseMenuWidget::SetupInputMode()
{
    if (APlayerController* PC = GetOwningPlayer())
    {
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(TakeWidget());
        PC->SetInputMode(InputMode);
    }
}

void UPauseMenuWidget::RestoreInputMode()
{
    if (APlayerController* PC = GetOwningPlayer())
    {
        FInputModeGameOnly InputMode;
        PC->SetInputMode(InputMode);
    }
}