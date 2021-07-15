#include "ScoreComponent.h"


UScoreComponent::UScoreComponent(){
	PrimaryComponentTick.bCanEverTick = false;
}

void UScoreComponent::IncrementScore(const int value){
	if(value > 0){
		CurrentScore += value;

		GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Green, FString::Printf(TEXT("Score: added %d point, now %d"), value, CurrentScore));
	}
}

int UScoreComponent::GetScore() const{
	return CurrentScore;
}