#include "MainMenuHUD.h"

#include "WidgetSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "GameStructs.h"


void AMainMenuHUD::BeginPlay() {
    UUserWidget* Menu = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->CreateWidget(EWidget::MainMenu);

    AllocatedMenu = Cast<UMainMenuWidget>(Menu);
    if(AllocatedMenu)
        if(GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AddToViewport(EWidget::MainMenu)){
            AllocatedMenu->OnNewGameStart.AddUObject(this, &AMainMenuHUD::OnClosingMenu);
            AllocatedMenu->OnQuitGame.AddUObject(this, &AMainMenuHUD::OnClosingMenu);
        }
}

void AMainMenuHUD::EndPlay() {
    OnClosingMenu();
}

void AMainMenuHUD::OnClosingMenu(){
    UUserWidget* Menu = GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->DeleteWidget(EWidget::MainMenu);

    AllocatedMenu == nullptr;
}