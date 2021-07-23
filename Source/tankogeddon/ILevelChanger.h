#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ILevelChanger.generated.h"


UINTERFACE(MinimalAPI)
class UILevelChanger : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TANKOGEDDON_API IILevelChanger
{
	GENERATED_BODY()

	public:
		virtual void SetActive(bool bState) = 0;
};
