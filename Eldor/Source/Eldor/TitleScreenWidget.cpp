#include "TitleScreenWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "EldorGameInstance.h"

UTitleScreenWidget::UTitleScreenWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , bExitHandled(false)
{
}

void UTitleScreenWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: NativeConstruct - Initializing title screen"));
    
    InitializeTitleText();
    BindExitButton();
}

void UTitleScreenWidget::NativeDestruct()
{
    UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: NativeDestruct"));
    Super::NativeDestruct();
}

void UTitleScreenWidget::SetTitleText(FString NewTitle)
{
    if (TitleText)
    {
        TitleText->SetText(FText::FromString(NewTitle));
        UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: Title text set to '%s'"), *NewTitle);
    }
}

FString UTitleScreenWidget::GetTitleText() const
{
    if (TitleText)
    {
        return TitleText->GetText().ToString();
    }
    return FString();
}

void UTitleScreenWidget::OnExitButtonClicked()
{
    if (bExitHandled)
    {
        UE_LOG(LogEldorGame, Warning, TEXT("TitleScreenWidget: Exit already handled, ignoring repeated click"));
        return;
    }
    
    bExitHandled = true;
    UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: Exit button clicked - requesting application exit"));
    
    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEldorGameInstance* EldorGI = Cast<UEldorGameInstance>(GameInstance))
        {
            EldorGI->RequestExit();
        }
    }
}

void UTitleScreenWidget::InitializeTitleText()
{
    if (TitleText)
    {
        TitleText->SetText(FText::FromString(TEXT("Eldor")));
        UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: TitleText initialized with 'Eldor'"));
    }
    else
    {
        UE_LOG(LogEldorGame, Warning, TEXT("TitleScreenWidget: TitleText binding not found"));
    }
}

void UTitleScreenWidget::BindExitButton()
{
    if (ExitButton)
    {
        ExitButton->OnClicked.AddDynamic(this, &UTitleScreenWidget::OnExitButtonClicked);
        UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: ExitButton click handler bound"));
    }
    else
    {
        UE_LOG(LogEldorGame, Warning, TEXT("TitleScreenWidget: ExitButton binding not found"));
    }
}