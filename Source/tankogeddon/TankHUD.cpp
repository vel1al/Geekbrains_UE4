#include "TankHud.h"

#include "WidgetSubsystem.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"

#include "GameStructs.h"


//idk what do with garbagecollector
void ATankHUD::SetActivePauseMenu(bool bActive) {
    if(AllocatedWidgets.Find(EWidget::Pause)){
        UUserWidget* buffer = *AllocatedWidgets.Find(EWidget::Pause);
        buffer->SetIsEnabled(bActive);
    }
}
void ATankHUD::SetActiveHUD(bool bActive) {    
    if(AllocatedWidgets.Find(EWidget::HUD)){
        UUserWidget* buffer = *AllocatedWidgets.Find(EWidget::HUD);
        buffer->SetIsEnabled(bActive);
    }
}
void ATankHUD::SetActiveGaveOver(bool bActive) {
    if(AllocatedWidgets.Find(EWidget::GameOver)){
        UUserWidget* buffer = *AllocatedWidgets.Find(EWidget::GameOver);
        buffer->SetIsEnabled(bActive);
    }
}

void ATankHUD::BeginPlay() {
    UUserWidget* PauseMenu = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AllocateWidget(EWidget::Pause);
    UUserWidget* HUD = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AllocateWidget(EWidget::HUD);
    UUserWidget* GameOver = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AllocateWidget(EWidget::GameOver);

    AllocatedWidgets.Add(EWidget::Pause, PauseMenu);
    AllocatedWidgets.Add(EWidget::HUD, HUD);
    AllocatedWidgets.Add(EWidget::GameOver, GameOver);

    GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AddWidgetToViewport(EWidget::HUD);

    if (GetWorld()){
        APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
            
        if (PlayerController){
            UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
            PlayerController->bShowMouseCursor = false;
        }
    }
}
// void ATankHUD::BeginDestroy() {
//     AllocatedWidgets.Empty();
// }

void ATankHUD::OnGameOverEnabling() {
    //do some effects
}