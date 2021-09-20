#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStructs.h"
#include "Projectile.h"

#include "PhysicsProjectile.generated.h"

UCLASS()
class TANKOGEDDON_API APhysicsProjectile : public AProjectile {
		GENERATED_BODY()
		
	public:
		APhysicsProjectile();

		void SetPrestartData(FPhysicsProjectilePreStartData PrestartData);
		void Start() override;

        UFUNCTION(BlueprintCallable)
        float GetProjectileMoveSpeed();

        UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
        class UParticleSystemComponent* TrailEffect;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PhysicsProjectile|Movement")
		float HighestSpeedAdjuster = 1.2;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PhysicsProjectile|Movement")
		float SlowestSpeedAdjuster = 0.8;
		
	protected:
		void End() override;

		void Move() override;

    private:
		FVector SupportPoint;
		FVector TargetPoint;
		FVector StartPoint;

		bool bIsFlying = false;

		float ShotDamage;
		float CurrentSpeed;

		FTimerHandle MovementTimerHandle;
};