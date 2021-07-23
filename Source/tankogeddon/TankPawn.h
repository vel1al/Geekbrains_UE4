#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IBody.h"
#include "IDamakeTaker.h"
#include "IScoreCounter.h"
#include "TankPawn.generated.h"


UCLASS()
class TANKOGEDDON_API ATankPawn : public APawn, public IIBody, public IIDamakeTaker, public IIScoreCounter{
		GENERATED_BODY()

	public:
		
		ATankPawn();
		
		UFUNCTION(BlueprintCallable, Category = "Tank|Health")
		bool CauseDamage(FDamageData DamageData) override;
		UFUNCTION(BlueprintCallable, Category = "Tank|Health")
		void Die() override;
		UFUNCTION(BlueprintCallable, Category = "Tank|Health")
		bool IsDestroyed() const override;

		virtual void Tick(const float DeltaTime) override;
		
		UFUNCTION(BlueprintCallable, Category = "Tank|Score")
		void IncrementScore(const int value) override;

		UFUNCTION(BlueprintCallable, Category = "Turret|Movement")
		void RotateTurretToStart();
		UFUNCTION(BlueprintCallable, Category = "Turret|Movement")
		void SetRotateTurretTorqueZAxis(const float InAxisValue) override;
		UFUNCTION(BlueprintCallable, Category = "Tank|Movement")
		void SetRotateTorqueZAxis(const float InAxisValue) override;
		UFUNCTION(BlueprintCallable, Category = "TankMovement")
		void SetMoveTorqueXAxis(const float InAxisValue) override;

		UFUNCTION(BlueprintCallable, Category = "Tank|Movement")
		float GetMoveTorqueXAxis() const;
		UFUNCTION(BlueprintCallable, Category = "Tank|Movement")
		float GetMoveSpeedXAxis() const;

		UFUNCTION(BlueprintCallable, Category = "TankFire")
		void FireMain() override;
		UFUNCTION(BlueprintCallable, Category = "TankFire")
		void FireSecond() override;

		UFUNCTION(BlueprintCallable, Category = "Turret")
		void SetUpTurret(TSubclassOf<ATankTurret> NewTurretClass);
		UFUNCTION(BlueprintCallable, Category = "Turret")
		void SetUpCannon(TSubclassOf<class ACanon> NewCannonClass);
		UFUNCTION(BlueprintCallable, Category = "Turret")
		void ChangeTurret();
		UFUNCTION(BlueprintCallable, Category = "Turret")
		FVector GetTurretDirection() const override;
		UFUNCTION(BlueprintCallable, Category = "Turret")
		FVector GetLookFromPosition() const;

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UStaticMeshComponent* BodyMesh;
		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class USpringArmComponent* SpringArm;
		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UCameraComponent* Camera;
    	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UBoxComponent* HitBox;
    	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
    	class UHealthComponent* HealthComponent;
		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
    	class UScoreComponent* ScoreComponent;
		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UArrowComponent* TurretSetupPoint;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UAudioComponent* PlayerHitAudioEffect;

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
    	class USoundBase* DestroyedAudioEffect;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		class UParticleSystem* DestroyedEffect;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turret")
		TSubclassOf<class ATankTurret> DefaultTurretClass;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank|Movement|AI", meta = (MakeEditWidget = true))
		TArray<FVector> LocalPatrollingPoints;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank|Movement")
		float TankMoveXAxisSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank|Movement")
		float TankRotationZAxisSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank|Movement")
		float TankRotationZAxisSensivity = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turret|Movement")
		float TurretRotationZAxisSpeed = 100.f;
    	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turret|Movement")
    	float TurretRotationSensitivity = 0.5;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank|AI|Movement")
		float TankMovementAccurancy = 5;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank|AI|Movement")
		float TankTargettingAccurancy = 5;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turret")
		int TurretSlotsCount = 2;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;
		virtual void Destroyed() override;

	private:
		UPROPERTY()
		ATankTurret* TankTurret;
		UPROPERTY()
		TArray<ATankTurret*> TurretSlots;


		ATankTurret* GetCurrentActiveTurret();

		int CurrentTurretSlot = 0;
		int AllocatedTurretSlotsCount = 0;
		int CurrentScore = 0;

		bool bIsRequringRotateToStart = false;
		bool bIsDestroyed = false;

		float CurrentTankMoveTorqueXAxis = 0.f;
		float CurrentTankRotationTorqueZAxis = 0.f;
		float CurrentTankRotationZAxis = 0.f;
		float CurrentTurretRotationTorqueZAxis = 0.f;
		float CurrentTurretRotationZAxis = 0.f;

		void MoveTankXAxis(const float DeltaTime);
		void RotateTankZAxis(const float DeltaTime);
		void RotateTurretZAxis(const float DeltaTime);

		void InvalidateTurret(int RequiredSlot);

		UFUNCTION()
		void DamageTook(float DamageValue); 
};