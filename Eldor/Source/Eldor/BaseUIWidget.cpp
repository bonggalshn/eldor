#include "BaseUIWidget.h"
#include "Logging/LogMacros.h"

UBaseUIWidget::UBaseUIWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , bInputEnabled(true)
{
    WidgetTintColor = FLinearColor::White;
    WidgetOpacity = 1.0f;
}

void UBaseUIWidget::NativeConstruct()
{
    Super::NativeConstruct();
    LogWidgetCreation();
}

void UBaseUIWidget::NativeDestruct()
{
    UE_LOG(LogEldorGame, Log, TEXT("BaseUIWidget: NativeDestruct called"));
    Super::NativeDestruct();
}

void UBaseUIWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
}

void UBaseUIWidget::SetWidgetOpacity(float NewOpacity)
{
    WidgetOpacity = FMath::Clamp(NewOpacity, 0.0f, 1.0f);
    SetRenderOpacity(WidgetOpacity);
}

void UBaseUIWidget::PlayFadeInAnimation(float Duration)
{
    UE_LOG(LogEldorGame, Log, TEXT("BaseUIWidget: PlayFadeInAnimation (%.2f seconds)"), Duration);
    // Animation binding would be set up in UMG designer
}

void UBaseUIWidget::PlayFadeOutAnimation(float Duration)
{
    UE_LOG(LogEldorGame, Log, TEXT("BaseUIWidget: PlayFadeOutAnimation (%.2f seconds)"), Duration);
    // Animation binding would be set up in UMG designer
}

void UBaseUIWidget::SetInputEnabled(bool bEnabled)
{
    bInputEnabled = bEnabled;
    UE_LOG(LogEldorGame, Log, TEXT("BaseUIWidget: Input %s"), bEnabled ? TEXT("enabled") : TEXT("disabled"));
}

void UBaseUIWidget::LogWidgetCreation() const
{
    UE_LOG(LogEldorGame, Log, TEXT("BaseUIWidget: Widget created - %s"), *GetName());
}