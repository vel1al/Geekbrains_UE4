#include "tankogeddon/Game/Subsystems/Public/TankGameModeBase.h"

#include "tankogeddon/Game/Vehicles/Player/Public/PlayerVehicle.h"
#include "tankogeddon/UI/TankHUD.h"

#include "GameFramework/HUD.h"
#include "Kismet/GameplayStatics.h"


void ATankGameModeBase::PlayerDie(){
    OnPlayerDieEvent();

    AHUD* HUD = UGameplayStatics::GetPlayerController(this,0)->GetHUD();
    ATankHUD* TankHUD = Cast<ATankHUD>(HUD);
    if(TankHUD)
        TankHUD->SetActiveGaveOver(true); 
}

TSubclassOf<UUserWidget> ATankGameModeBase::GetDefaultClass(EWidget Key){
    if(DefaultWidgetClases.Contains(Key))
        return DefaultWidgetClases[Key];

    return nullptr;
}

TArray<FObstacle> ATankGameModeBase::GetDefaultObstacles(){
    return DefaultObstacles;
}