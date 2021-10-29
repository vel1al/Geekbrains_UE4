#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStructs.h"
#include "CannonBase.generated.h"

UCLASS()
class TANKOGEDDON_API ACanonBase : public AActor{
		GENERATED_BODY()
		
	public:	
		ACanonBase();

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* Mesh;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UArrowComponent* ProjectileSpawnPoint;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UParticleSystemComponent* ShootEffect;
    	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UAudioComponent* ShootAudioEffect;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UAudioComponent* ElminatedAudioEffect;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		class UForceFeedbackEffect* ShootForceEffect;
    	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
    	TSubclassOf<class UMatineeCameraShake> ShootShake;

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
		float FireDamage = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|General")
		float FireRange = 1000.f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Main")
		float MainFireCooldownTime = 2.f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Second")
		float SecondFireCooldownTime = 5.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Second")
		float SecondIntervalTime = 0.25;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire|Attack|Second");
		int SecondShotsCount = 4;

		UFUNCTION(BlueprintCallable, Category = "Fire")
		virtual void FireMain(const float AdditionDamage);
		UFUNCTION(BlueprintCallable, Category = "Fire")
		virtual void FireSecond(const float AdditionDamage);
		UFUNCTION(BlueprintPure, Category = "Fire")
		bool IsReadyToFire() const;

		UFUNCTION(BlueprintCallable, Category = "Ammo")
		void RestoreAmmo();
		UFUNCTION(BlueprintCallable, Category = "Ammo")
		void AddAmmo(const int AdditionalAmmoValue);

	protected:
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;
		
		void Reload();
		void Cooldown();

		virtual void Fire();

		virtual void SecondShot();
		virtual void MainShot();

        bool bIsReadyToFire = false;
	
		int CurrentSecondShot;
		int CurrentAmmoCount;	
		int CurrentAmmunitionCount;

		float AdditionDamage;
	
		FTimerHandle ReloadTimerHandle;
		FTimerHandle CooldownTimerHandle;
		FTimerHandle SecondIntervalTimerHandle;
};