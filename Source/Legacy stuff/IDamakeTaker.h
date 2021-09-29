#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameStructs.h"
#include "IDamakeTaker.generated.h"


UINTERFACE(MinimalAPI)
class UIDamakeTaker : public UInterface{
		GENERATED_BODY()
};

/**
 * 
 */
class TANKOGEDDON_API IIDamakeTaker{
		GENERATED_BODY()
	
	public:
		virtual bool CauseDamage(FDamageData DamageData) = 0;

		virtual void Die() = 0;

		virtual bool IsDestroyed() const = 0;
};