#include "TankGameModeBase.h"
#include "PlayerVechicle.h"
#include "TankHUD.h"
#include "GameFramework/HUD.h"
#include "Kismet/GameplayStatics.h"


void ATankGameModeBase::PlayerDie(){
    OnPlayerDieEvent();

    AHUD* HUD = UGameplayStatics::GetPlayerController(this,0)->GetHUD();
    ATankHUD* TankHUD = Cast<ATankHUD>(HUD);
    if(TankHUD)
        TankHUD->SetActiveGaveOver(true); 
}