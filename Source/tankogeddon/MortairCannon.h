#pragma once

#include "CoreMinimal.h"
#include "GameStructs.h"
#include "CannonBase.h"

#include "MortairCannon.generated.h"


UCLASS()
class TANKOGEDDON_API AMortairCanon : public ACanonBase{
		GENERATED_BODY()
		
	public:	
		void Fire() override;

		void SetTarget(const FVector2D value);
		void SetSupportPoint(const FVector value);

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting|Trajectory")
		float DeadZ = -10;
	
	protected:
		FVector TargetPoint;
		FVector SupportPoint;
};