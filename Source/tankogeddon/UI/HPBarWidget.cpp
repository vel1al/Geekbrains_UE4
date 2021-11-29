#include "HPBarWidget.h"

#include "Components/ProgressBar.h"


void UHPBarWidget::SetHP(int Percentage) {
    if(HPProgressBar)
        HPProgressBar->SetPercent(Percentage);
}