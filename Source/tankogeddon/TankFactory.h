#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDamakeTaker.h"
#include "IEmeny.h"
#include "GameStructs.h"
#include "TankFactory.generated.h"


UCLASS()
class TANKOGEDDON_API ATankFactory : public AActor, public IIDamakeTaker, public IIEmeny {
		GENERATED_BODY()
		
	public:	
		ATankFactory();

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* DefaultMesh;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* ColapsedMesh;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UArrowComponent* TankSpawnPoint;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UBoxComponent* HitBox;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UHealthComponent* HealthComponent;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UParticleSystemComponent* ColapseEffect;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UAudioComponent* ColapseAudioEffect;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UParticleSystemComponent* OnNewTankSpawnEffect;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UAudioComponent* OnNewTankSpawnAudioEffect;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		class UForceFeedbackEffect* ColapseForceEffect;
    	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
    	TSubclassOf<class UMatineeCameraShake> ColapseShake;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TankFactory|Spawning")
		float SpawnRate = 1;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TankFactory|Spawning")
		TSubclassOf<class ATankPawn> DefaultTankClass;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TankFactory|Spawning", Meta = (MakeEditWidget = true))
		TArray<FVector> PatrollingWays;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TankFactory|LevelChange")
		AActor* LevelChanger;


		UFUNCTION(BlueprintCallable, Category = "Damage")
		bool CauseDamage(FDamageData DamageData) override;
		UFUNCTION(BlueprintCallable, Category = "Damage")
		bool IsDestroyed() const override;

		UFUNCTION(BlueprintCallable, Category = "Score")
		int GetScoreValue() const override;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "TankFactory|Score")
		int ElminatedScoreValue = 5;

	protected:
		virtual void BeginPlay() override;
		virtual void Destroyed() override;

	private:
		void SpawnNewTank();

		void ChangeMeshState(const bool state);

		UFUNCTION()
		void Die();


		FTimerHandle TankSpawningDelayTimerHandle;

		bool bIsColapsed;
};
