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


		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float MoveXAxisSpeed = 100.f;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float StrafeYAxisSpeed = 100.f;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:
		// Called every frame
		virtual void Tick(const float DeltaTime) override;

		UFUNCTION(BlueprintCallable, Category = "Movement")
		void MoveXAxis(const float InAxisValue);
		UFUNCTION(BlueprintCallable, Category = "Movement")
		void MoveYAxis(const float InAxisValue);

	private:
		float CurrentTorqueXAxis = 0.f;
		float CurrentTorqueYAxis = 0.f;
};