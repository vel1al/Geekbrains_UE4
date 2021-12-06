#include "tankogeddon/Game/Subsystems/Public/WidgetSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "tankogeddon/Game/Subsystems/Public/TankGameModeBase.h"


void UWidgetSubsystem::Init(TMap<EWidget, TSubclassOf<UUserWidget>> WidgetClassesToBind) {
    WidgetClasses = WidgetClassesToBind;
}

bool UWidgetSubsystem::AddWidgetToViewport(EWidget RequiredWidget, int ZOrder){
    if(RequiredWidget == EWidget::None)
        return false;

    UUserWidget* WidgetToAddToViewport = nullptr;
    if(!AllocatedWidgets.Contains(RequiredWidget)) 
        WidgetToAddToViewport = AllocateWidget(RequiredWidget);
    else 
        WidgetToAddToViewport = AllocatedWidgets[RequiredWidget];

    if(!WidgetToAddToViewport) 
        return false;
    
    WidgetToAddToViewport->AddToViewport(ZOrder);

    return true;
}

bool UWidgetSubsystem::RemoveWidgetFromViewport(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return false;
    if(!AllocatedWidgets.Contains(RequiredWidget))
        return false;
    
    UUserWidget* WidgetToRemoveFromViewport = AllocatedWidgets[RequiredWidget];
    if(!WidgetToRemoveFromViewport){
        AllocatedWidgets.Remove(RequiredWidget);
        return false;
    }

    WidgetToRemoveFromViewport->RemoveFromViewport();

    return true;
}

bool UWidgetSubsystem::DeleteWidget(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return false;
    if(!AllocatedWidgets.Contains(RequiredWidget))
        return false;

    UUserWidget* WidgetToDelete = AllocatedWidgets[RequiredWidget];
    if(!WidgetToDelete) {
        AllocatedWidgets.Remove(RequiredWidget);
        return false;
    }
    
    WidgetToDelete->RemoveFromParent();
    AllocatedWidgets.Remove(RequiredWidget);

    return true;
}

UUserWidget* UWidgetSubsystem::AllocateWidget(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return nullptr;
    if(!WidgetClasses.Contains(RequiredWidget))
        return nullptr;
    
    UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClasses[RequiredWidget]);

    AllocatedWidgets.Add(RequiredWidget, NewWidget);
        
    return NewWidget;
}

UUserWidget* UWidgetSubsystem::GetAllocatedWidget(EWidget RequiredWidget) const {
    if(RequiredWidget == EWidget::None)
        return nullptr;
    if(!AllocatedWidgets.Contains(RequiredWidget))
        return nullptr;

    return AllocatedWidgets[RequiredWidget];
}

void UWidgetSubsystem::SetActiveWidget(EWidget RequiredWidget, bool bActive) {
    UUserWidget* Widget = GetAllocatedWidget(RequiredWidget);
    if(!Widget)
        return;

    if(bActive)
        Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    else
        Widget->SetVisibility(ESlateVisibility::Collapsed);
}