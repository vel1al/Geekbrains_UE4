#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "Player.generated.h"


UCLASS()
class TANKOGEDDON_API UPlayer : public UDamageTaker{
		GENERATED_BODY()

	public:
		int GetScore() const;

		void AddScore(const int value);

	protected:
		int CurrentScore;
};