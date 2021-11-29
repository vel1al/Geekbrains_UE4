#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "DialogWidget.generated.h"

class UButton;


UCLASS()
class TANKOGEDDON_API UDialogWidget : public UUserWidget{
        GENERATED_BODY()

    public:
        void NativeConstruct() override;

        DECLARE_EVENT(UDialogWidget, FOnCancel);
        DECLARE_EVENT(UDialogWidget, FOnApply);

        FOnCancel OnCancel;
        FOnApply OnApply;

    protected:
        UPROPERTY(meta = (BindWidgetOptional))
        UButton* Apply_btn;
        UPROPERTY(meta = (BindWidgetOptional))
        UButton* Cancel_btn;

        UFUNCTION()
        void OnApplyButtonPressed();
        UFUNCTION()
        void OnCancelButtonPressed();
};