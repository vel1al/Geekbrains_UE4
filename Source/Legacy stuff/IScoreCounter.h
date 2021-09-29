#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IScoreCounter.generated.h"


UINTERFACE(MinimalAPI)
class UIScoreCounter : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TANKOGEDDON_API IIScoreCounter{
	GENERATED_BODY()

	public:
		virtual void IncrementScore(class AActor* SecondActor) = 0;
};
