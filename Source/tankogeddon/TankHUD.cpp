#include "TankHud.h"

#include "WidgetSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "GameStructs.h"


//idk what do with garbagecollector
void ATankHud::SetActivePauseMenu(bool bActive) {
    if(AllocatedWidgets[EWidget::Pause])
        AllocatedWidgets[EWidget::Pause]->SetEnabled(bActive);
}
void ATankHud::SetActiveHUD(bool bActive) {    
    if(AllocatedWidgets[EWidget::HUD])
        AllocatedWidgets[EWidget::HUD]->SetEnabled(bActive);
}
void ATankHud::SetActiveGaveOver(bool bActive) {
    if(AllocatedWidgets[EWidget::GameOver])
        AllocatedWidgets[EWidget::GameOver]->SetEnabled(bActive);
}

void ATankHud::BeginPlay() {
    UUserWidget* PauseMenu = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->CreateWidget(EWidget::Pause);
    UUserWidget* HUD = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->CreateWidget(EWidget::HUD);
    UUserWidget* GameOver = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->CreateWidget(EWidget::GameOver);

    AllocatedWidgets.Add(EWidget::Pause, PauseMenu);
    AllocatedWidgets.Add(EWidget::HUD, HUD);
    AllocatedWidgets.Add(EWidget::GameOver, GameOver);

    GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AddWidgetToViewport(EWidget::HUD);
}
void ATankHud::EndPlay() {
    AllocatedWidgets.Empty();
}

void ATankHud::OnGameOverEnabling() {
    //do some effects
}