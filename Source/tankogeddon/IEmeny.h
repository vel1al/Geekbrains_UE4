#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEmeny.generated.h"


UINTERFACE(MinimalAPI)
class UIEmeny : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TANKOGEDDON_API IIEmeny
{
	GENERATED_BODY()

	public:
		virtual int GetScoreValue() const = 0;
		virtual bool IsDestroyed() const = 0;
};
