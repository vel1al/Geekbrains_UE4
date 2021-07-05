// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TankTurret.generated.h"

UCLASS()
class TANKOGEDDON_API ATankTurret : public AActor{
		GENERATED_BODY()
		
	public:
		ATankTurret();
		
		UFUNCTION(BlueprintCallable, Category = "Cannon")
		void SetUpCannon(TSubclassOf<class ACanon> NewCannonClass);
		UFUNCTION(BlueprintCallable, Category = "Cannon")
		void SetActive(bool bIsActive);
		UFUNCTION(BlueprintCallable, Category = "Cannon")
		void RestoreAmmo();

		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireMain();
		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireSecond();

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

		void InvalidateCannon();
};
