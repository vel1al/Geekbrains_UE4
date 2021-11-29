#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "QuestSystemPlugin/Public/Core/QuestManager.h"

#include "TankPlayerState.generated.h"


UCLASS()
class TANKOGEDDON_API ATankPlayerState : public APlayerState{
	GENERATED_BODY()
		
	public:
		FOnEnemyKill OnKilled;
		FOnScoreReceive OnScoreReceive;
	
		UFUNCTION(BlueprintCallable)
		void IncrementScore(const int32 Value = 1, AActor* KilledActor = nullptr);
		int GetScore();

		void PlayerDie();
		bool IsPlayerAlive();

	private:
		bool bIsPlayerAlive = false;
		int CurrentScore = 0;
};
