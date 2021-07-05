// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretBox.generated.h"

UCLASS()
class TANKOGEDDON_API ATurretBox : public AActor{
		GENERATED_BODY()
		
	public:	
		ATurretBox();

		virtual void Tick(const float DeltaTime) override;
		

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Mesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Turret")
		TSubclassOf<class ATankTurret> TurretClass;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Movement")
		float RotationRatio;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Movement")
		float FlyingHeightRatio;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Movement")
		float FlyingSpeedRatio;

	protected:
		float SinDegrees = 1.f;

		FVector ConstLocation;
		FRotator ConstRotation;

		virtual void BeginPlay() override;

		UFUNCTION()
		void OnMeshOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
