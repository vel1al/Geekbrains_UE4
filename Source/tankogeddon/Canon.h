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

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float FireReloadTime = 7.f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float MainFireRange = 1000.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float MainFireDamage = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float MainFireCooldownTime = 2.f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float SecondFireRange = 1000.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float SecondFireDamage = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float SecondFireCooldownTime = 5.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float QueueIntervalTime = 0.25;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings");
		int QueueShotsCount = 4;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings");
		int AmmoCount = 10;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		ECannonType Type = ECannonType::FireProjectile;

		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireMain();

		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireSecond();

		UFUNCTION(BlueprintPure, Category = "Fire")
		bool IsReadyToFire() const;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float DebugMsgTime = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire settings")
		float DebugMsgTimeQ = 0.25;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;

	private:
		void Reload();
		void Cooldown();

		void QueueShot();
		void MainShot();

		bool bIsReadyToFire = false;
		bool bIsQueueEnd = true;

		int CurrentAmmoCount;	

		FTimerHandle ReloadTimerHandle;
		FTimerHandle CooldownTimerHandle;
		FTimerHandle QueueIntervalTimerHandle;
};