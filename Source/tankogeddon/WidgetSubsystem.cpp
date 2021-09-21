#include "WidgetSubsystem.h"

#include "Blueprint/UserWidget.h"


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

UUserWidget* UWidgetSubsystem::AllocateWidget(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return nullptr;

    UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultWidgetClases[RequiredWidget]);

    if(!NewWidget)
        return nullptr;

    AllocatedWidgets.Add(RequiredWidget, NewWidget);
    
    return NewWidget;
}


void UWidgetSubsystem::BeginDestroy(){
    AllocatedWidgets.Empty();
    ViewportWidgets.Empty();
}