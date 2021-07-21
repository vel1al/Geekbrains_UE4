// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBody.h"
#include "IDamakeTaker.h"
#include "IEmeny.h"
#include "TowerBody.generated.h"


UCLASS()
class TANKOGEDDON_API ATowerBody : public APawn, public IIDamakeTaker, public IIEmeny{
		GENERATED_BODY()
		
	public:	
		ATowerBody();

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UStaticMeshComponent* BodyMesh;

    	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UBoxComponent* HitBox;

    	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
    	class UHealthComponent* HealthComponent;

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UArrowComponent* TurretSetupPoint;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret")
		TSubclassOf<class ATowerTurret> DefaultTurretClass;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float TargetingRange = 1000;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float TargetingSpeedDegrees = 40.f;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float TargetingRate = 0.005f;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float Accurency = 10;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Score")
		int ScoreValue = 0;
		
		UFUNCTION(BlueprintCallable, Category = "Turret")
		void SetUpTurret(TSubclassOf<class ATowerTurret> NewTurretClass);
		UFUNCTION(BlueprintCallable, Category = "Turret")
		FVector GetTurretDirection() const;
		UFUNCTION(BlueprintCallable, Category = "Turret")
		void RotateTurretYAxis();
	

		UFUNCTION(BlueprintCallable, Category = "Health")
		bool CauseDamage(FDamageData DamageData) override;
		UFUNCTION(BlueprintCallable, Category = "Health")
		void Die() override;

		UFUNCTION(BlueprintCallable, Category = "Health")
		int GetScoreValue() const override;

	protected:
		void Tick(const float DeltaTime) override;
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;

	private:
		float GetAngleToPlayer();

		bool CheckRange();

		void Fire();

		void InvalidateTurret();

		UFUNCTION()
		void DamageTook(float DamageValue);

    	UPROPERTY()
    	class ATowerTurret* Turret;

	    UPROPERTY()
   		APawn* PlayerPawn;

		float AngleToPlayer;
		float TargetingSpeed;
};
