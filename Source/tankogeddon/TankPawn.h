// Fill out your copyright notice in the Description page of Project Settings.

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
		
		UFUNCTION(BlueprintCallable, Category = "Health")
		bool CauseDamage(FDamageData DamageData) override;
		UFUNCTION(BlueprintCallable, Category = "Health")
		void Die() override;

		virtual void Tick(const float DeltaTime) override;
		
		UFUNCTION(BlueprintCallable, Category = "Score")
		void IncrementScore(const int value) override;

		UFUNCTION(BlueprintCallable, Category = "Movement")
		void SetMoveTorqueXAxis(const float InAxisValue);
		UFUNCTION(BlueprintCallable, Category = "Movement")
		void SetRotateTorqueYAxis(const float InAxisValue);

		UFUNCTION(BlueprintCallable, Category = "Movement")
		float GetMoveTorqueXAxis() const;
		UFUNCTION(BlueprintCallable, Category = "Movement")
		float GetMoveSpeedXAxis() const;

		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireMain() override;
		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireSecond() override;

		UFUNCTION(BlueprintCallable, Category = "Turret")
		void SetUpTurret(TSubclassOf<ATankTurret> NewTurretClass);

		UFUNCTION(BlueprintCallable, Category = "Turret")
		void SetUpCannon(TSubclassOf<class ACanon> NewCannonClass);

		UFUNCTION(BlueprintCallable, Category = "Turret")
		void ChangeTurret();

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

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turret")
		TSubclassOf<class ATankTurret> DefaultTurretClass;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float TankMoveXAxisSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float TankRotationYAxisSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float TankRotationYAxisSensivity = 100.f;

    	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    	float TurretRotationSensitivity = 0.5;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Turret")
		int TurretSlotsCount = 2;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;
	

	private:
		UPROPERTY()
		ATankTurret* TankTurret;
		UPROPERTY()
		class ATankPlayerController* TankController;
		UPROPERTY()
		TArray<ATankTurret*> TurretSlots;


		ATankTurret* GetCurrentActiveTurret();
		void MoveTankXAxis(const float DeltaTime);
		void RotateTankYAxis(const float DeltaTime);
		virtual void RotateTurretYAxis() override;

		void InvalidateTurret(int RequiredSlot);

		UFUNCTION()
		void DamageTook(float DamageValue);

		int CurrentTurretSlot = 0;
		int AllocatedTurretSlotsCount = 0;
		int CurrentScore = 0;

		float CurrentTankMoveTorqueXAxis = 0.f;
		float CurrentTankRotationTorqueYAxis = 0.f;
		float CurrentTankRotationYAxis = 0.f;
};