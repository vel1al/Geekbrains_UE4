#include "TurretCell.h"

#include "TowerBodyBase.h"
#include "TankPlayerController.h"

#include "Blueprint/WidgetBlueprintLibrary.h"

#include "Components/HorizontalBox.h"
#include "Components/Image.h"


FReply UTurretCell::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent){
    if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)){
        if(bIsDraggable)
   	        return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
        else
            if(CreateDraggableActor.IsBound())
                CreateDraggableActor.Execute(DraggedTurretClass);
    }

    return FReply::Handled();
}

void UTurretCell::SetDraggable(bool bState){
    bIsDraggable = bState;
}

void UTurretCell::NativeOnDragDetected(const FGeometry & InGeometry, const FPointerEvent & InMouseEvent, UDragDropOperation *& OutOperation){
    OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDropOperation::StaticClass());

    if (OutOperation){
   	    OutOperation->DefaultDragVisual = this;

   	    SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 0.7f));
   	    SetVisibility(ESlateVisibility::SelfHitTestInvisible);

   	    OutOperation->OnDragCancelled.AddDynamic(this, &UTurretCell::OnDragCancelledHandle);
    }
    else    
   	    Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}

void UTurretCell::OnDragCancelledHandle(UDragDropOperation* Operation){
    SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 1.f));
    SetVisibility(ESlateVisibility::Visible);
}

FName UTurretCell::GetTurretName() {
    return TurretName;
}

void UTurretCell::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent){
    if(ShowPopUp.IsBound())
        ShowPopUp.Execute(GetTurretName());
}
void UTurretCell::NativeOnMouseLeave(const FPointerEvent& InMouseEvent){
    if(HidePopUp.IsBound())
        HidePopUp.Execute();
}

bool UTurretCell::NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation){
    auto* HorizontalBox = Cast<UHorizontalBox>(GetParent());
    UDragDropOperation* TurretCellOperation = InOperation;

    if (!TurretCellOperation && !HorizontalBox || this == InOperation->DefaultDragVisual)
        return Super::NativeOnDragOver(InGeometry, InDragDropEvent, InOperation);

    int32 DraggedIndex = HorizontalBox->GetChildIndex(InOperation->DefaultDragVisual);

    if (DraggedIndex == -1)
        return Super::NativeOnDragOver(InGeometry, InDragDropEvent, InOperation);

    FVector2D MouseOnWidgetPosition = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
    FVector2D WidgetLocalSize = InGeometry.GetLocalSize();

    bool Modificator = (MouseOnWidgetPosition.X > (WidgetLocalSize.X / 2));

    HorizontalBox->RemoveChildAt(DraggedIndex);
    TArray<UWidget*> Childrens = HorizontalBox->GetAllChildren();
    HorizontalBox->ClearChildren();

    for (int32 Cell = 0; Cell < Childrens.Num(); ++Cell){
   		if(Modificator)
           HorizontalBox->AddChildToHorizontalBox(Childrens[Cell]);
        
        if(Childrens[Cell] == this)
   		    HorizontalBox->AddChildToHorizontalBox(TurretCellOperation->DefaultDragVisual);
        
        if(!Modificator)
            HorizontalBox->AddChildToHorizontalBox(Childrens[Cell]);
   	}

    return Super::NativeOnDragOver(InGeometry, InDragDropEvent, InOperation);
}

bool UTurretCell::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation){
    if (!InOperation && !InOperation->DefaultDragVisual)
        return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
   	Cast<UUserWidget>(InOperation->DefaultDragVisual)->SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 1.f));
   	InOperation->DefaultDragVisual->SetVisibility(ESlateVisibility::Visible);
    
    return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}