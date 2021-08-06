#include "ScoreComponent.h"
#include "IEmeny.h"

UScoreComponent::UScoreComponent(){
	PrimaryComponentTick.bCanEverTick = false;
}

void UScoreComponent::IncrementScore(AActor* SecondActor){
	if (SecondActor){
        IIEmeny* EmenyActor = Cast<IIEmeny>(SecondActor);

        if(EmenyActor)
            CurrentScore += EmenyActor->GetScoreValue();
    }
}

int UScoreComponent::GetScore() const{
	return CurrentScore;
}