#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Containers/Array.h"
#include "ProjectilePoolManagerSubSystem.generated.h"


UCLASS()
class TANKOGEDDON_API UProjectilePoolManagerSubSystem : public UGameInstanceSubsystem {
	GENERATED_BODY()
	
	public:
		UFUNCTION(BlueprintCallable)
		class UProjectilePoolManager* GetProjectilePoolManager(TSubclassOf<class AProjectile> ProjectileClass);

	private:
		UPROPERTY()
		TArray<class UProjectilePoolManager*> ProjectilePoolManagers;
};