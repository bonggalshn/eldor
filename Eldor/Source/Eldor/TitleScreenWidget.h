#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleScreenWidget.generated.h"

class UTextBlock;
class UButton;

/**
 * UTitleScreenWidget
 * UMG widget for the Eldor title screen
 * Displays "Eldor" game title and handles user interactions
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class ELDOR_API UTitleScreenWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UTitleScreenWidget(const FObjectInitializer& ObjectInitializer);

    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category="TitleScreen")
    void SetTitleText(FString NewTitle);

    UFUNCTION(BlueprintCallable, Category="TitleScreen")
    FString GetTitleText() const;

protected:
    UPROPERTY(BlueprintReadOnly, Category="TitleScreen", meta=(BindWidgetOptional))
    UTextBlock* TitleText;

    UPROPERTY(BlueprintReadOnly, Category="TitleScreen", meta=(BindWidgetOptional))
    UButton* ExitButton;

    UPROPERTY(BlueprintReadOnly, Category="TitleScreen", meta=(BindWidgetOptional))
    UButton* NewGameButton;

    UFUNCTION(BlueprintCallable, Category="TitleScreen")
    virtual void OnExitButtonClicked();

    UFUNCTION(BlueprintCallable, Category="TitleScreen")
    virtual void OnNewGameButtonClicked();

private:
    bool bExitHandled;
    void InitializeTitleText();
    void BindExitButton();
    void BindNewGameButton();
};