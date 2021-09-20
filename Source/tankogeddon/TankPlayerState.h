#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TankPlayerState.generated.h"


UCLASS()
class TANKOGEDDON_API ATankPlayerState : public APlayerState{
	GENERATED_BODY()
	
	public:
		void IncrementScore();
		int GetScore();

		void PlayerDie();
		bool IsPlayerAlive();

	private:
		bool bIsPlayerAlive = false;
		int CurrentScore = 0;
};
