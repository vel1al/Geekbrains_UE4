#include "TankPlayerState.h"
#include "TankGameModeBase.h"


void ATankPlayerState::IncrementScore(){
    CurrentScore += 1;
}
int ATankPlayerState::GetScore(){
    return CurrentScore;
}

void ATankPlayerState::PlayerDie(){
    bIsPlayerAlive = true;

    ATankGameModeBase* CurrentGameMode = Cast<ATankGameModeBase>(GetWorld()->GetAuthGameMode());
    if(CurrentGameMode)
        CurrentGameMode->OnPlayerDieEvent();
}
bool ATankPlayerState::IsPlayerAlive(){
    return bIsPlayerAlive;
}