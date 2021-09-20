#include "WidgetSubsystem.h"

#include "Blueprint/UUserWidget.h"


bool AddWidgetToViewport(EWidget RequiredWidget, int ZOrder = 0){
    if(RequiredWidget == EWidget::None)
        return false;
    
    UUserWidget* NewWidget = AlocatedWidgets.Findkey(RequiredWidget);

    if(!NewWidget)
        return false;

    NewWidget->AddToViewport(ZOrder);
    
    ViewportWidgets.Add(NewWidget, RequiredWidget);

    return true;
}

bool RemoveWidgetFromViewport(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return false;

    UUserWidget* RequiredWidget = ViewportWidgets.Findkey(RequiredWidget);

    if(!UUserWidget)
        return false;

    RequiredWidget->RemoveFromParent();

    return true;
}

bool DeleteWidget(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return false;

    UUserWidget* RequiredWidget = AlocatedWidgets.Findkey(RequiredWidget);

    if(!UUserWidget)
        return false;

    RequiredWidget->RemoveFromParent();
    RequiredWidget->BeginDestroy();

    return true;
}

UUserWidget* CreateWidget(EWidget RequiredWidget){
    if(RequiredWidget == EWidget::None)
        return nullptr;

    UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultWidgetClases[RequiredWidget]);

    if(!NewWidget)
        return nullptr;

    AllocatedWidgets.Add(NewWidget, RequiredWidget);
    
    return NewWidget;
}


void BeginDestroy(){
    AllocatedWidgets.Empty();
    ViewportWidgets.Empty();
}