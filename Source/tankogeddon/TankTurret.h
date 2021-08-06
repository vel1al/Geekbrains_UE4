#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretBase.h"
#include "TankTurret.generated.h"


UCLASS()
class TANKOGEDDON_API ATankTurret : public ATurretBase{
		GENERATED_BODY()
		
	public:
		UFUNCTION(BlueprintCallable, Category = "Cannon")
		void SetActive(bool bIsActive);
};
