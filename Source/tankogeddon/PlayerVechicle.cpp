#include "PlayerVechicle.h"
#include "Emeny.h"

void APlayerVechicle::IncrementScore(AActor* SecondActor){
	if (SecondActor){
        AEmeny* EmenyActor = Cast<AEmeny>(SecondActor);

        if(EmenyActor)
            CurrentScore += EmenyActor->GetDestructionPoints();
    }
}

int APlayerVechicle::GetScore() const{
	return CurrentScore;
}