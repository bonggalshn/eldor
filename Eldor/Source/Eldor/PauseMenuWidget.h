#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuWidget.generated.h"

class UButton;

/**
 * UPauseMenuWidget
 * UMG widget for the in-game pause menu
 * Displays pause menu overlay with navigation and exit options
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class ELDOR_API UPauseMenuWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPauseMenuWidget(const FObjectInitializer& ObjectInitializer);

    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category = "PauseMenu")
    void ShowMenu();

    UFUNCTION(BlueprintCallable, Category = "PauseMenu")
    void HideMenu();

protected:
    UPROPERTY(BlueprintReadOnly, Category = "PauseMenu", meta = (BindWidgetOptional))
    TObjectPtr<UButton> ReturnToMenuButton;

    UPROPERTY(BlueprintReadOnly, Category = "PauseMenu", meta = (BindWidgetOptional))
    TObjectPtr<UButton> ExitToDesktopButton;

    UFUNCTION(BlueprintCallable, Category = "PauseMenu")
    virtual void OnReturnToMenuClicked();

    UFUNCTION(BlueprintCallable, Category = "PauseMenu")
    virtual void OnExitToDesktopClicked();

private:
    void BindButtons();
    void SetupInputMode();
    void RestoreInputMode();
};