#pragma once

#include "CoreMinimal.h"
#include "UMG/Slate/Public/Widgets/SUserWidget.h"
#include "BaseUIWidget.generated.h"

/**
 * UBaseUIWidget
 * Base class for all Eldor UI widgets
 * Provides common functionality for styling, animation, and state management
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class ELDOR_API UBaseUIWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UBaseUIWidget(const FObjectInitializer& ObjectInitializer);

    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
    UFUNCTION(BlueprintCallable, Category="UI")
    void SetWidgetOpacity(float NewOpacity);

    UFUNCTION(BlueprintCallable, Category="UI")
    void PlayFadeInAnimation(float Duration = 0.5f);

    UFUNCTION(BlueprintCallable, Category="UI")
    void PlayFadeOutAnimation(float Duration = 0.5f);

    UFUNCTION(BlueprintCallable, Category="UI")
    void SetInputEnabled(bool bEnabled);

    UFUNCTION(BlueprintCallable, Category="UI")
    void LogWidgetCreation() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
    FLinearColor WidgetTintColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
    float WidgetOpacity = 1.0f;

private:
    bool bInputEnabled;
};