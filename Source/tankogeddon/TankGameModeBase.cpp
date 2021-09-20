#include "TankGameModeBase.h"
#include "PlayerVechicle.h"
#include "TankHUD.h"
#include "GameFramework/HUD.h"


void ATankGameModeBase::PlayerDie(){
    OnPlayerDieEvent();

    AHud* HUD = GetHud();
    ATankHud* TankHUD = Cast<ATankHud>(HUD);
    if(TankHUD)
        TankHUD->SetActiveGaveOver(true); 
}