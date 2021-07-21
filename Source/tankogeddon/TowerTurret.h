// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ITurret.h"
#include "TowerTurret.generated.h"

UCLASS()
class TANKOGEDDON_API ATowerTurret : public AActor, public IITurret{
		GENERATED_BODY()
		
	public:
		ATowerTurret();
		
		UFUNCTION(BlueprintCallable, Category = "Cannon")
		void SetUpCannon(TSubclassOf<class ACanon> NewCannonClass) override;
		UFUNCTION(BlueprintCallable, Category = "Cannon")
		void RestoreAmmo() override;

		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireMain() override;
		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireSecond() override;

		UFUNCTION(BlueprintCallable, Category = "Movement")
		FVector GetTurretMeshDirection() const override;
		UFUNCTION(BlueprintCallable, Category = "Movement")
		FRotator GetTurretMeshRotation() const override;
		UFUNCTION(BlueprintCallable, Category = "Movement")
		void SetTurretMeshRotation(const FRotator value) override;

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UStaticMeshComponent* TurretMesh;

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UArrowComponent* CannonSetupPoint;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cannon")
		TSubclassOf<class ACanon> DefaultCannonClass;

	protected:
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;
	private:
		UPROPERTY()
		ACanon* Cannon = nullptr;

		void InvalidateCannon() override;
};
