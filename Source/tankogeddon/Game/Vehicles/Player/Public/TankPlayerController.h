// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


UCLASS()
class TANKOGEDDON_API ATankPlayerController : public APlayerController{
	GENERATED_BODY()

	public:
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMouseButtonUp);
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShift, bool, bIsPreesed);

		FOnMouseButtonUp OnMouseButtonUp;
		FOnShift OnLeftShift;
	
		ATankPlayerController();

		virtual void BeginPlay() override;
		virtual void SetupInputComponent() override;
		virtual void Tick(float DeltaSeconds) override;

		UFUNCTION(BlueprintPure, Category = "Input")
		FVector GetMousePos() const;

		UFUNCTION()
		void OnMouseButtonUpFunc();

		UFUNCTION()
		void OnLeftShiftPressed();
		UFUNCTION()
		void OnLeftShiftReleased();
	
	private:
		void MoveXAxis(float AxisValue);
		void RotateZAxis(float AxisValue);
		
		void FireMain();
		void FireSecond();
		void ChangeTurret();

		void Interaction();
	
		void OpenInvetory();
		void CloseInvetory();
	
	private:
		UPROPERTY()
		class APlayerVehicle* PlayerVehicle;

		FVector CachedMousePosition;
		FVector PreviousMousePosition;

		bool bIsControllingByMouse;
		bool bIsIventoryOpened;
};