#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerBodyBase.h"

#include "MortairTowerBody.generated.h"


UCLASS()
class TANKOGEDDON_API AMortairTowerBody : public ATowerBodyBase {
		GENERATED_BODY()
		
	public:	
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Cannon|Targeting")
		float TargetingCannonSpeedDegrees = 40.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Cannon|Targeting")
		float CannonTargetingSensitivity = 0.005f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Cannon|Targeting")
		float CannonVisualAccurency = 10;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Cannon|Targeting|Trajectory")
		float HeightAdjuster;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Cannon|Targeting|Trajectory")
		float PositionAdjuster;

		UFUNCTION(BlueprintCallable, Category = "Cannon")
		virtual void RotateCannonXAxis(const FVector TargetPoint);

	protected:
		virtual void Tick(const float DeltaTime) override;
		virtual void BeginPlay() override;

		virtual void CastTurretToClass() override;

	private:
        virtual FVector GetBalisticPoint(const FVector TargetPoint);

		UPROPERTY()
    	class AMortairTurret* Turret;

		float TargetingVerticalSpeed;
		float CurretCannonRotationTorque;
};

// #pragma once

// #include "CoreMinimal.h"
// #include "GameFramework/Actor.h"
// #include "IBody.h"
// #include "IDamakeTaker.h"
// #include "IEmeny.h"
// #include "MortairTowerBody.generated.h"


// UCLASS()
// class TANKOGEDDON_API AMortairTowerBody : public APawn, public IIDamakeTaker, public IIEmeny {
// 		GENERATED_BODY()
		
// 	public:	
// 		AMortairTowerBody();

// 		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
// 		class UStaticMeshComponent* BodyMesh;
//     	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
//     	class UBoxComponent* HitBox;
//     	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
//     	class UHealthComponent* HealthComponent;
// 		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
// 		class UArrowComponent* TurretSetupPoint;

// 		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
//     	class USoundBase* DestroyedAudioEffect;
// 		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
// 		class UParticleSystem* DestroyedEffect;

// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret")
// 		TSubclassOf<class ATowerTurret> DefaultTurretClass;

// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
// 		float TargetingRange = 1000;
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
// 		float TargetingHorizontalSpeedDegrees = 40.f;
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
// 		float TargetingVerticalSpeedDegrees = 40.f;
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
// 		float TargetingRate = 0.005f;
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
// 		float TurretAccurency = 10;

// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting|Trajectory")
// 		float HeightAdjuster;
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting|Trajectory")
// 		float PositionAdjuster;
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting|Trajectory")
// 		float TrajectoryDistance = 0.005f;
		
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Cannon|Targeting")
// 		float CannonTargetingSensitivity = 0.005f;
// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Cannon|Targeting")
// 		float CannonVisualAccurency = 10;

// 		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Score")
// 		int ScoreValue = 0;
		
// 		UFUNCTION(BlueprintCallable, Category = "Turret")
// 		virtual void SetUpTurret(TSubclassOf<class ATowerTurret> NewTurretClass);
// 		UFUNCTION(BlueprintCallable, Category = "Turret")
// 		FVector GetTurretDirection() const;
// 		UFUNCTION(BlueprintCallable, Category = "Turret")
// 		virtual void RotateTurretYAxis(const FVector TargetPoint);

// 		UFUNCTION(BlueprintCallable, Category = "Cannon")
// 		virtual void RotateCannonXAxis(const FVector TargetPoint);

// 		UFUNCTION(BlueprintCallable, Category = "Health")
// 		bool CauseDamage(FDamageData DamageData) override;
// 		UFUNCTION(BlueprintCallable, Category = "Health")
// 		void Die() override;	
// 		UFUNCTION(BlueprintCallable, Category = "Health")
// 		bool IsDestroyed() const override;

// 		UFUNCTION(BlueprintCallable, Category = "Health")
// 		int GetScoreValue() const override;

// 	protected:
// 		void Tick(const float DeltaTime) override;
// 		virtual void BeginPlay() override;
// 		virtual void EndPlay(EEndPlayReason::Type Reason) override;

// 	private:
// 		virtual float GetAngleFromTo(const FVector CurrentPoint, const FVector TargetPoint);
//         virtual FVector GetBalisticPoint(const FVector TargetPoint);

// 		virtual bool CheckRange();

// 		virtual void Fire();

// 		virtual void InvalidateTurret();

// 		UFUNCTION()
// 		void DamageTook(float DamageValue);

//     	UPROPERTY()
//     	class ATowerTurret* Turret;

// 	    UPROPERTY()
//    		APawn* PlayerPawn;

// 		float AngleToPlayer;
// 		float TargetingHorizontalSpeed;
// 		float TargetingVerticalSpeed;
// 		float CurretCannonRotationTorque;

// 		bool bIsDestroyed = false;
// };