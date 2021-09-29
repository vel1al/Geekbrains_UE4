#include "MainMenuHUD.h"

#include "WidgetSubsystem.h"
#include "MainMenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"

#include "GameStructs.h"


void AMainMenuHUD::BeginPlay() {
    AllocatedMainMenu = Cast<UMainMenuWidget>(GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AllocateWidget(EWidget::MainMenu));
    
    if(AllocatedMainMenu){
        if(GetGameInstance()->GetSubsystem<UWidgetSubsystem>()->AddWidgetToViewport(EWidget::MainMenu)){
            AllocatedMainMenu->OnNewGameStart.AddUObject(this, &AMainMenuHUD::OnClosingMenu);
            AllocatedMainMenu->OnQuitGame.AddUObject(this, &AMainMenuHUD::OnClosingMenu);
        }
        
        if (GetWorld()){
            APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
            
            if (PlayerController){
                UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController, nullptr, EMouseLockMode::DoNotLock, false);

                PlayerController->bShowMouseCursor = true;
            }
        }
    }
}

// void AMainMenuHUD::BeginDestroy() {
//     OnClosingMenu();
// }

void AMainMenuHUD::OnClosingMenu(){
    //AllocatedMainMenu = nullptr;
}