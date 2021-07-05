// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TANKOGEDDON_API AProjectile : public AActor{
		GENERATED_BODY()
		
	public:
		AProjectile();

		void Start(FVector StartPosition, FRotator StartRotation);
		
		virtual void EndPlay(EEndPlayReason::Type Reason) override;

		UFUNCTION(BlueprintCallable)
		bool IsUsing() const;

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Mesh;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float MoveSpeed = 100.f;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float MoveRate = 0.005f;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
		float MoveRange = 1000.f;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage")
		float Damage = 1.f;

	protected:
		bool bIsUsing = false;

		float PassedWay;

		FTimerHandle MovementTimerHandle;

		void End();

		UFUNCTION()
		void Move();

		UFUNCTION()
		void OnMeshOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};