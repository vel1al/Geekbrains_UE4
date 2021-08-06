#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretBase.generated.h"


UCLASS()
class TANKOGEDDON_API ATurretBase : public AActor{
		GENERATED_BODY()
		
	public:
		ATurretBase();

		UFUNCTION(BlueprintCallable, Category = "Cannon")
		virtual void SetUpCannon(TSubclassOf<class ACanonBase> NewCannonClass);
		UFUNCTION(BlueprintCallable, Category = "Cannon")
		void RestoreAmmo();

		UFUNCTION(BlueprintCallable, Category = "Fire")
		virtual void FireMain();
		UFUNCTION(BlueprintCallable, Category = "Fire")
		virtual void FireSecond();

		UFUNCTION(BlueprintCallable, Category = "Movement|Turret")
		FVector GetTurretMeshDirection() const;
		UFUNCTION(BlueprintCallable, Category = "Movement|Turret")
		FRotator GetTurretMeshRotation() const;
		UFUNCTION(BlueprintCallable, Category = "Movement|Turret")
		void SetTurretMeshRotation(const FRotator value);

		UFUNCTION(BlueprintCallable, Category = "Movement|Cannon")
		ACanonBase* GetCannon() const;
		UFUNCTION(BlueprintCallable, Category = "Movement|Cannon")
		void SetCannonRotation(const FRotator value);

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UStaticMeshComponent* TurretMesh;
		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UArrowComponent* CannonSetupPoint;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cannon")
		TSubclassOf<class ACanonBase> DefaultCannonClass;

	protected:
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;
	
		void InvalidateCannon();

        virtual void CastCannonToClass();

        UPROPERTY()
		ACanonBase* BaseCannon = nullptr;
};
 