#include "PlayerVechicle.h"
#include "Emeny.h"
//#include "TankPlayerState"

#include "Kismet/GameplayStatics.h"


void APlayerVechicle::IncrementScore(AActor* SecondActor){
	//PlayerState->IncrementScore();
    return;
}

int APlayerVechicle::GetScore() const{
	//PlayerState->GetScore();
    return 1;
}


void APlayerVechicle::OnDieEvent() {
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestroyedEffect, GetActorTransform());
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), DestroyedAudioEffect, GetActorLocation());

    //PlayerState->PlayerDeath();
}