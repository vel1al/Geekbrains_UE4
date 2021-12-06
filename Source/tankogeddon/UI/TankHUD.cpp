#include "TankHud.h"

#include "tankogeddon/Game/Subsystems/Public/WidgetSubsystem.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"

#include "tankogeddon/Game/Misc/GameStructs.h"
#include "tankogeddon/Game/Subsystems/Public/TankGameModeBase.h"


void ATankHUD::SetActiveWidget(EWidget RequiredWidget, bool bState) {
    WidgetSubsystem->SetActiveWidget(RequiredWidget, bState);
}

void ATankHUD::BeginPlay() {
    WidgetSubsystem = GetGameInstance()->GetSubsystem<UWidgetSubsystem>();
    if(!WidgetSubsystem)
        return;

    ATankGameModeBase* TankGameModeBase = GetWorld()->GetAuthGameMode<ATankGameModeBase>();
    if(!TankGameModeBase)
        return;

    WidgetSubsystem->Init(TankGameModeBase->GetDefaultClasses());
    
    UUserWidget* PauseMenu = WidgetSubsystem->AllocateWidget(EWidget::Pause);
    UUserWidget* HUD = WidgetSubsystem->AllocateWidget(EWidget::HUD);
    UUserWidget* GameOver = WidgetSubsystem->AllocateWidget(EWidget::GameOver);
    UUserWidget* QuestJournal = WidgetSubsystem->AllocateWidget(EWidget::QuestJournal);
    UUserWidget* QuestHUD = WidgetSubsystem->AllocateWidget(EWidget::QuestHUD);
    
    AllocatedWidgets.Add(EWidget::Pause, PauseMenu);
    AllocatedWidgets.Add(EWidget::HUD, HUD);
    AllocatedWidgets.Add(EWidget::GameOver, GameOver);
    AllocatedWidgets.Add(EWidget::QuestJournal, QuestJournal);
    AllocatedWidgets.Add(EWidget::QuestHUD, QuestHUD);
    
    WidgetSubsystem->AddWidgetToViewport(EWidget::Pause);
    WidgetSubsystem->AddWidgetToViewport(EWidget::HUD);
    WidgetSubsystem->AddWidgetToViewport(EWidget::GameOver);
    WidgetSubsystem->AddWidgetToViewport(EWidget::QuestJournal);
    WidgetSubsystem->AddWidgetToViewport(EWidget::QuestHUD);
    
    if (GetWorld()){
        APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
            
        if (PlayerController){
            UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
            PlayerController->bShowMouseCursor = false;
        }
    }
}
