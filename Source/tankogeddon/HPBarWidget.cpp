#include "HPBarWidget.h"

#include "Components/ProgressBar.h"


void UHPBarWidget::SetHP(int Percentage) {
    if(ProgressBar)
        ProgressBar->SetPercent(Percentage);
}