#include "tankogeddon/Game/Subsystems/Public/WidgetSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "tankogeddon/Game/Subsystems/Public/TankGameModeBase.h"


void UWidgetSubsystem::UpdateGameModeRef(){
    CurrentGameMode = Cast<ATankGameModeBase>(GetWorld()->GetAuthGameMode());
}

bool UWidgetSubsystem::AddWidgetToViewport(EWidget RequiredWidget, int ZOrder){
    if(RequiredWidget == EWidget::None)
        return false;
    
    UUserWidget* NewWidget = *AllocatedWidgets.Find(RequiredWidget);

    if(!NewWidget)
        return false;

    NewWidget->AddToViewport(ZOrder);
    
    ViewportWidgets.Add(RequiredWidget, NewWidget);

    return true;
}

bool UWidgetSubsystem::RemoveWidgetFromViewport(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return false;

    UUserWidget* FindedWidget = *ViewportWidgets.Find(RequiredWidget);

    if(!FindedWidget)
        return false;

    FindedWidget->RemoveFromParent();

    return true;
}

bool UWidgetSubsystem::DeleteWidget(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return false;

    UUserWidget* FindedWidget = *AllocatedWidgets.Find(RequiredWidget);

    if(!FindedWidget)
        return false;

    FindedWidget->RemoveFromParent();
    FindedWidget->BeginDestroy();

    return true;
}

void UWidgetSubsystem::ToggleWidgetVisibility(EWidget Widget, const bool bState) {
    if(Widget == EWidget::None)
        return;

    if(!AllocatedWidgets.Contains(Widget))
        return;

    if(bState)
        AllocatedWidgets[Widget]->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    else
        AllocatedWidgets[Widget]->SetVisibility(ESlateVisibility::Collapsed);
}

UUserWidget* UWidgetSubsystem::AllocateWidget(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return nullptr;
    
    if(!(CurrentGameMode)){
        UpdateGameModeRef();

        if(!(CurrentGameMode))
            return nullptr;
    }

    UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), CurrentGameMode->GetDefaultClass(RequiredWidget));

    if(!NewWidget)
        return nullptr;

    AllocatedWidgets.Add(RequiredWidget, NewWidget);
        
    return NewWidget;
}

// void UWidgetSubsystem::BeginDestroy(){
//     // AllocatedWidgets.Empty();
//     // ViewportWidgets.Empty();
//     // CurrentGameMode = nullptr;
// }