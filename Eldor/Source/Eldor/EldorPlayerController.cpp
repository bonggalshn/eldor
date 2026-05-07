#include "EldorPlayerController.h"
#include "Components/InputComponent.h"
#include "Logging/LogMacros.h"
#include "EldorGameInstance.h"
#include "PauseMenuWidget.h"

AEldorPlayerController::AEldorPlayerController()
    : Super()
    , bIsPauseMenuVisible(false)
{
    PauseMenuWidgetClass = nullptr;
}

void AEldorPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        InputComponent->BindKey(FKey(TEXT("Escape")), IE_Pressed, this, &AEldorPlayerController::TogglePauseMenu);
        UE_LOG(LogEldorGame, Log, TEXT("EldorPlayerController: Escape key bound"));
    }
}

void AEldorPlayerController::TogglePauseMenu()
{
    UE_LOG(LogEldorGame, Log, TEXT("EldorPlayerController: TogglePauseMenu called"));

    UGameInstance* GI = GetGameInstance();
    if (!GI)
    {
        UE_LOG(LogEldorGame, Warning, TEXT("EldorPlayerController: No GameInstance"));
        return;
    }

    UEldorGameInstance* EldorGI = Cast<UEldorGameInstance>(GI);
    if (!EldorGI)
    {
        UE_LOG(LogEldorGame, Warning, TEXT("EldorPlayerController: Not EldorGameInstance"));
        return;
    }

    if (!EldorGI->IsPlaying())
    {
        UE_LOG(LogEldorGame, Log, TEXT("EldorPlayerController: Not in Playing mode, ignoring Escape"));
        return;
    }

    if (bIsPauseMenuVisible)
    {
        UE_LOG(LogEldorGame, Log, TEXT("EldorPlayerController: Hiding pause menu"));
        if (PauseMenuWidgetInstance.IsValid())
        {
            PauseMenuWidgetInstance->HideMenu();
            PauseMenuWidgetInstance.Reset();
        }
        bIsPauseMenuVisible = false;
    }
    else
    {
        UE_LOG(LogEldorGame, Log, TEXT("EldorPlayerController: Showing pause menu"));

        if (!PauseMenuWidgetClass)
        {
            UE_LOG(LogEldorGame, Warning, TEXT("EldorPlayerController: PauseMenuWidgetClass not set"));
            return;
        }

        if (!PauseMenuWidgetInstance.IsValid())
        {
            PauseMenuWidgetInstance = CreateWidget<UPauseMenuWidget>(this, PauseMenuWidgetClass);
        }

        if (PauseMenuWidgetInstance.IsValid())
        {
            PauseMenuWidgetInstance->ShowMenu();
            bIsPauseMenuVisible = true;
        }
    }
}