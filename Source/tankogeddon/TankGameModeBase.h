#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Widget.h"

#include "TankGameModeBase.generated.h"


UCLASS()
class TANKOGEDDON_API ATankGameModeBase : public AGameModeBase{
	GENERATED_BODY()
	
	public:
		void PlayerDie();

		UFUNCTION(BlueprintImplementableEvent)
		void OnPlayerDieEvent();
};
