// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKOGEDDON_API ATankPlayerController : public APlayerController{
	GENERATED_BODY()

	public:
		ATankPlayerController();

		virtual void BeginPlay() override;
		virtual void SetupInputComponent() override;
		virtual void Tick(float DeltaSeconds) override;

		UFUNCTION(BlueprintPure, Category = "Input")
		FVector GetMousePos() const;

	private:
		void MoveXAxis(float AxisValue);
		void RotateYAxis(float AxisValue);
		
		void FireMain();
		void FireSecond();
		void ChangeTurret();

	private:
		UPROPERTY()
		class ATankPawn* TankPawn;

		FVector CachedMousePosition;
};