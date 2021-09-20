#include "DialogWidget.h"

#include "Components/Button.h"


void UDialogWidget::NativeConstruct() {
    Super::NativeConstruct();

    if(Apply_btn)
        Apply_btn->OnClicked.AddDynamic(this, &UDialogWidget::OnApplyButtonPressed);
    if(Cancel_btn)
        Apply_btn->OnClicked.AddDynamic(this, &UDialogWidget::OnCancelButtonPressed);
}

void UDialogWidget::OnApplyButtonPressed() {
    OnApply.Broadcast();
}

void UDialogWidget::OnCancelButtonPressed() {
    OnCancel.Broadcast();

    SetIsEnabled(false);
}