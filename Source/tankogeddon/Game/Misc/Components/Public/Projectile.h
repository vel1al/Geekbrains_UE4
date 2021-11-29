#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "tankogeddon/Game/Misc/GameStructs.h"
#include "Projectile.generated.h"

UCLASS()
class TANKOGEDDON_API AProjectile : public AActor{
		GENERATED_BODY()
		
	public:
		AProjectile();

		UFUNCTION(BlueprintCallable, Category = "Projectile")
		virtual void Start();

		UFUNCTION(BlueprintCallable, Category = "Projectile")
		void SetPrestartData(FProjectilePreStartData PrestartData);

		UFUNCTION(BlueprintCallable)
		bool IsUsing() const;

		UFUNCTION(BlueprintCallable)
		void SetMoveRange(const float value);

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* Mesh;

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		class USoundBase* ExplosionAudioEffect;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		class UParticleSystem* ExplosionEffect;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile|Movement")
		float MoveSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile|Movement")
		float MoveRate = 0.005f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile|Damage")
		float ProjectileDamage = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile|Damage")
		float PushForce = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile|Explode")
		bool bIsExploding = false;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile|Explode|Damage")
		float ProjectileExplosionDamage = 1.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile|Explode|Damage")
		float ProjectileExplosionRadius = 10.f;


	protected:
		virtual void End();
		virtual void EndPlay(EEndPlayReason::Type Reason) override;

		void DoExplodeHit();
		void DoFlatHit(AActor* OtherActor);

		void OnExplodeEffects() const;

		void AplyDamage(AActor* OtherActor);
		void AplyPushForce(AActor* OtherActor);

		UFUNCTION()
		virtual void Move();

		UFUNCTION()
		void OnMeshOverlapBegin(class UPrimitiveComponent* OverlappedComp, 
										class AActor* OtherActor,
										class UPrimitiveComponent* OtherComp, 
										int32 OtherBodyIndex,
										bool bFromSweep, 
										const FHitResult& SweepResult);

		bool bIsUsing = false;

	private:
		float MoveRange = 1000.f;

		float PassedWay;
		float ShotDamage;

		FTimerHandle MovementTimerHandle;
};