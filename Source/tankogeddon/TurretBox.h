#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretBox.generated.h"

UCLASS()
class TANKOGEDDON_API ATurretBox : public AActor{
		GENERATED_BODY()
		
	public:	
		ATurretBox();

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* Mesh;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class USpotLightComponent* Light;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Turret")
		TSubclassOf<class ATurretBase> TurretClass;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Movement")
		float RotationRatio;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Movement")
		float FlyingHeightRatio;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Movement")
		float FlyingSpeedRatio;

	protected:
		virtual void BeginPlay() override;
		virtual void Tick(const float DeltaTime) override;

	private:
		float SinDegrees = 1.f;

		FVector ConstLocation;
		FRotator ConstRotation;

		UFUNCTION()
		void OnMeshOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
