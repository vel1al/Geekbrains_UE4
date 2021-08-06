#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "TankFactory.generated.h"


UCLASS()
class TANKOGEDDON_API ATankFactory : public ADamageTaker {
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

	protected:
		virtual void BeginPlay() override;
		virtual void Destroyed() override;

		virtual void OnDieEvent() override;

	private:
		void SpawnNewTank();

		void ChangeMeshState(const bool state);

		FTimerHandle TankSpawningDelayTimerHandle;
};
