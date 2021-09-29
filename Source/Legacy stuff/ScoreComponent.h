#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKOGEDDON_API UScoreComponent : public UActorComponent{
		GENERATED_BODY()

	public:	
		UScoreComponent();

		void IncrementScore(class AActor* SecondActor);
		
		int GetScore() const;

	protected:
		UPROPERTY()
		int CurrentScore;
};
