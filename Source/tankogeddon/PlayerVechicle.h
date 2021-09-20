#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "PlayerVechicle.generated.h"


UCLASS()
class TANKOGEDDON_API APlayerVechicle : public ADamageTaker{
		GENERATED_BODY()

	public:
		virtual void OnDieEvent() override;

		void IncrementScore(AActor* SecondActor);
        int GetScore() const;
};
