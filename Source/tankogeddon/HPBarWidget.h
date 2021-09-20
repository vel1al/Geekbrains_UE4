#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "HPBarWidget.generated.h"

class UProgressBar;


UCLASS()
class TANKOGEDDON_API UHPBarWidget : public UUserWidget{
        GENERATED_BODY()

    public:
        void SetHP(int Percentage);

    protected:
        UPROPERTY(meta = (BindWidget))
        UProgressBar* ProgressBar;
};
