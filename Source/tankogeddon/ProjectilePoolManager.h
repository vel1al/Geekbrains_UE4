// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Array.h"
#include "Tickable.h"
#include "ProjectilePoolManager.generated.h"


UCLASS()
class TANKOGEDDON_API UProjectilePoolManager : public UObject, public FTickableGameObject{
	GENERATED_BODY()
	
	public:
		UProjectilePoolManager();

		virtual void Tick(const float DeltaTime) override;
		virtual bool IsTickable() const override;
		virtual TStatId GetStatId() const override;

		virtual void PostInitProperties() override;
		//virtual void BeginDestroy() override;

		UFUNCTION(BlueprintCallable)
		void BeginPlay();

		TSubclassOf<class AProjectile> GetProjectileClass() const;
		void SetProjectileClass(TSubclassOf<class AProjectile> ProjectileClass);

		UFUNCTION(BlueprintCallable, Category = "PoolManagment")
		class AProjectile* GetProjectile();

		UFUNCTION(BlueprintCallable, Category = "PoolManagment")
		AProjectile* CreateProjectile();

	private:
		class AProjectile* FirstAvaibleObject = nullptr;
		class AProjectile* FindNextAvaibleObject();

		UPROPERTY()
		TArray<class AProjectile*> AllocatedObjects;
		UPROPERTY()
		TSubclassOf<class AProjectile> ProjectileClass;
};
