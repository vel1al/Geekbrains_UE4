#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerBodyBase.h"
#include "TowerBody.generated.h"


UCLASS()
class TANKOGEDDON_API ATowerBody : public ATowerBodyBase{
		GENERATED_BODY()

	protected:
		virtual void Tick(const float DeltaTime) override;

		bool IsPlayerInView();

		float TurretTargetingAngle;
};
