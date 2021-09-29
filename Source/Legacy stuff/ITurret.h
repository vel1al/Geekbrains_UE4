#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ITurret.generated.h"


UINTERFACE(MinimalAPI)
class UITurret : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TANKOGEDDON_API IITurret{
	GENERATED_BODY()

	public:
		virtual void SetUpCannon(TSubclassOf<class ACanon> NewCannonClass) = 0;
		virtual void InvalidateCannon() = 0;

		virtual void RestoreAmmo() = 0;

		virtual void FireMain() = 0;
		virtual void FireSecond() = 0;

		virtual FVector GetTurretMeshDirection() const = 0;
		
		virtual FRotator GetTurretMeshRotation() const = 0;
		virtual void SetTurretMeshRotation(const FRotator value) = 0;
};
