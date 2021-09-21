#include "MainMenuHUD.h"

#include "WidgetSubsystem.h"
#include "MainMenuWidget.h"

#include "Blueprint/UserWidget.h"
#include "GameStructs.h"


void AMainMenuHUD::BeginPlay() {
    UUserWidget* Menu = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AllocateWidget(EWidget::MainMenu);

    AllocatedMainMenu = Cast<UMainMenuWidget>(Menu);
    if(AllocatedMainMenu)
        if(GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AddWidgetToViewport(EWidget::MainMenu)){
            AllocatedMainMenu->OnNewGameStart.AddUObject(this, &AMainMenuHUD::OnClosingMenu);
            AllocatedMainMenu->OnQuitGame.AddUObject(this, &AMainMenuHUD::OnClosingMenu);
        }
}

void AMainMenuHUD::BeginDestroy() {
    OnClosingMenu();
}

void AMainMenuHUD::OnClosingMenu(){
    GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->DeleteWidget(EWidget::MainMenu);

    AllocatedMainMenu = nullptr;
}