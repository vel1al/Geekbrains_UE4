// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStructs.h"
#include "Canon.generated.h"

UCLASS()
class TANKOGEDDON_API ACanon : public AActor{
		GENERATED_BODY()
		
	public:	
		// Sets default values for this actor's properties
		ACanon();

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* Mesh;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UArrowComponent* ProjectileSpawnPoint;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Cannon")
		TSubclassOf<class AProjectile> ProjectileClass;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Cannon");
		int AmmunitionCount = 300;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Cannon");
		int AmmoCount = 10;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Cannon")
		ECannonType Type = ECannonType::FireProjectile;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|General")
		float FireReloadTime = 7.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|General")
		float FireRange = 7.f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Main")
		float MainFireDamage = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Main")
		float MainFireCooldownTime = 2.f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Second")
		float SecondFireDamage = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Second")
		float SecondFireCooldownTime = 5.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Second")
		float QueueIntervalTime = 0.25;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Second");
		int QueueShotsCount = 4;

		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireMain();
		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireSecond();

		UFUNCTION(BlueprintCallable, Category = "Ammo")
		void RestoreAmmo();

		UFUNCTION(BlueprintPure, Category = "Fire")
		bool IsReadyToFire() const;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;

	private:
		void Reload();
		void Cooldown();

		void Fire();

		void QueueShot();
		void MainShot();

		bool bIsReadyToFire = false;
	
		int CurrentQueueShot;
		int CurrentAmmoCount;	
		int CurrentAmmunitionCount;

		FTimerHandle ReloadTimerHandle;
		FTimerHandle CooldownTimerHandle;
		FTimerHandle QueueIntervalTimerHandle;

		//class UProjectilePoolManager* ProjectilePoolManager;
};