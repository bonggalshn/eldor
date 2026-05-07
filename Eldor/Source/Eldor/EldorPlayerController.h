#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EldorPlayerController.generated.h"

class UPauseMenuWidget;

/**
 * AEldorPlayerController
 * Handles player input including escape key for pause menu
 */
UCLASS()
class ELDOR_API AEldorPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AEldorPlayerController();

protected:
    virtual void SetupInputComponent() override;

    void TogglePauseMenu();

private:
    UPROPERTY(EditDefaultsOnly, Category="UI")
    TSubclassOf<UPauseMenuWidget> PauseMenuWidgetClass;

    UPROPERTY()
    UPauseMenuWidget* PauseMenuWidgetInstance;

    bool bIsPauseMenuVisible;
};