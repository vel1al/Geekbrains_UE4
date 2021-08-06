#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretBase.h"

#include "MortairTurret.generated.h"


UCLASS()
class TANKOGEDDON_API AMortairTurret : public ATurretBase{
		GENERATED_BODY()
		
    public:
        virtual class AMortairCanon* GetMortairCannon() const;

	protected:
		virtual void BeginPlay() override;
        virtual void CastCannonToClass() override;
           
    private:
        UPROPERTY()
        class AMortairCanon* Cannon = nullptr;
};