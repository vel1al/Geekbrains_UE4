#include "tankogeddon/Game/Vehicles/Player/Public/TankPlayerState.h"
#include "tankogeddon/Game/Subsystems/Public/TankGameModeBase.h"


void ATankPlayerState::IncrementScore(const int32 Value, AActor* KilledActor){
    CurrentScore += Value;

    //if(OnScoreReceive)
        if(OnScoreReceive.IsBound())
            OnScoreReceive.Broadcast(Value);
    
    if(KilledActor)
        //if(OnKilled)
            if(OnKilled.IsBound())
                OnKilled.Broadcast(KilledActor);
}


int ATankPlayerState::GetScore(){
    return CurrentScore;
}

void ATankPlayerState::PlayerDie(){
    bIsPlayerAlive = false;

    ATankGameModeBase* CurrentGameMode = Cast<ATankGameModeBase>(GetWorld()->GetAuthGameMode());
    if(CurrentGameMode)
        CurrentGameMode->OnPlayerDieEvent();
}
bool ATankPlayerState::IsPlayerAlive(){
    return bIsPlayerAlive;
}