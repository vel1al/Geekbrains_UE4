// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEmeny.generated.h"

// This class does not need to be modified.
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
};
