// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

UCLASS()
class TANKOGEDDON_API ATankPawn : public APawn{
		GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ATankPawn();

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UStaticMeshComponent* BodyMesh;
		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		UStaticMeshComponent* TurretMesh;

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class USpringArmComponent* SpringArm;

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UCameraComponent* Camera;

		UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Components")
		class UArrowComponent* CannonSetupPoint;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cannon")
		TSubclassOf<class ACanon> CannonClass;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float TankMoveXAxisSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float TankRotationYAxisSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float TankRotationYAxisSensivity = 100.f;

    	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    	float TurretRotationSensitivity = 0.5;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		virtual void EndPlay(EEndPlayReason::Type Reason) override;

	public:
		// Called every frame
		virtual void Tick(const float DeltaTime) override;

		UFUNCTION(BlueprintCallable, Category = "Movement")
		void SetMoveTorqueXAxis(const float InAxisValue);
		UFUNCTION(BlueprintCallable, Category = "Movement")
		void SetRotateTorqueYAxis(const float InAxisValue);

		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireMain();
		UFUNCTION(BlueprintCallable, Category = "Fire")
		void FireSecond();

	private:
		UPROPERTY()
		ACanon* Cannon;
		UPROPERTY()
		class ATankPlayerController* TankController = nullptr;

		void MoveTankXAxis(const float DeltaTime);
		void RotateTankYAxis(const float DeltaTime);
		void RotateTurretYAxis();

		void SetUpCannon();
		void InvalidateCannon();

		float CurrentTankMoveTorqueXAxis = 0.f;
		float CurrentTankRotationTorqueYAxis = 0.f;
		float CurrentTankRotationYAxis = 0.f;
};