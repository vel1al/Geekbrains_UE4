#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class TANKOGEDDON_API ATankAIController : public AAIController{
	GENERATED_BODY()

    public:
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Patrooling", Meta = (MakeEditWidget = true))
        TArray<FVector> GlobalPatrollingPoints;

        UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI|Targeting")
        float TargetingRange = 1000.f;

    protected:
        virtual void BeginPlay() override;
        virtual void Tick(float DeltaTime) override;	

    private:
        int LastPatroolPointIndex = INDEX_NONE;
        FVector CurrentPatroolPoint;

        UPROPERTY()
	    class ATankPawn* ControllingTank;

        void Initialize();
};