#include "TitleScreenWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "EldorGameInstance.h"
#include "Kismet/GameplayStatics.h"

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
    BindNewGameButton();
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

void UTitleScreenWidget::OnNewGameButtonClicked()
{
    UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: New Game button clicked - initiating world transition"));

    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEldorGameInstance* EldorGI = Cast<UEldorGameInstance>(GameInstance))
        {
            EldorGI->SetCurrentGameMode(EGameMode::Playing);
        }
    }

    UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: Loading World level"));
    UGameplayStatics::OpenLevel(this, FName(TEXT("World")), true);
}

void UTitleScreenWidget::BindNewGameButton()
{
    if (NewGameButton)
    {
        NewGameButton->OnClicked.AddDynamic(this, &UTitleScreenWidget::OnNewGameButtonClicked);
        UE_LOG(LogEldorGame, Log, TEXT("TitleScreenWidget: NewGameButton click handler bound"));
    }
    else
    {
        UE_LOG(LogEldorGame, Warning, TEXT("TitleScreenWidget: NewGameButton binding not found"));
    }
}