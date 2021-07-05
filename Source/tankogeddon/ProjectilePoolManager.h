// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
// #include "Containers/Array.h"
// #include "Tickable.h"
#include "ProjectilePoolManager.generated.h"


UCLASS()
class TANKOGEDDON_API UProjectilePoolManager : public UObject{//, public FTickableGameObject{
	GENERATED_BODY()
	
	// public:
	// 	UProjectilePoolManager();

	// 	virtual void Tick(const float DeltaTime) override;
	// 	virtual bool IsTickable() const override;
	// 	virtual TStatId GetStatId() const override;

	// 	UFUNCTION(BlueprintCallable, Category = "PoolManagment")
	// 	class AProjectile* GetProjectile();

	// private:
	// 	TArray<class AProjectile*> AllocatedObjects;

	// 	AProjectile* FirstAvaibleObject = nullptr;

	// 	AProjectile* FindNextAvaibleObject();
};
