#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Emeny.h"

#include "TowerBodyBase.generated.h"


UCLASS()
class TANKOGEDDON_API ATowerBodyBase : public AEmeny{
		GENERATED_BODY()
		
	public:	
		ATowerBodyBase();

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UStaticMeshComponent* BodyMesh;
    	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UBoxComponent* HitBox;
		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UArrowComponent* TurretSetupPoint;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret")
		TSubclassOf<class ATurretBase> DefaultTurretClass;
 
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float TurretTargetingRange = 1000;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float TurretTargetingSpeedDegrees = 40.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float TurretTargetingRate = 0.005f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower|Turret|Targeting")
		float TurretTargetingAccurency = 10;
		

		UFUNCTION(BlueprintCallable, Category = "Turret")
		virtual void SetUpTurret(TSubclassOf<class ATurretBase> NewTurretClass);
		UFUNCTION(BlueprintCallable, Category = "Turret")
		FVector GetTurretDirection() const;
		UFUNCTION(BlueprintCallable, Category = "Turret")
		virtual void RotateTurretYAxis(const FVector TargetPoint);

	protected:
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;

		virtual void CastTurretToClass();

		float GetAngleFromTo(const FVector FromDirection, const FVector ToDirection);

		bool CheckRange();

		virtual void Fire();

		virtual void InvalidateTurret(); 

		UPROPERTY()
		class ATurretBase* BaseTurret;
		UPROPERTY()
   		APawn* PlayerPawn;

		float TurretTargetingSpeed;
};
