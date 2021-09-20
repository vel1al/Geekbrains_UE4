#include "HPBarWidget.h"

#include "Components/ProgressBar.h"


void SetHP(int Percentage) {
    if(ProgressBar)
        ProgressBar->SetPercent(Percentage);
}