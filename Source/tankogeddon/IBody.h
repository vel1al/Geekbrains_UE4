// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBody.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIBody : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TANKOGEDDON_API IIBody{
	GENERATED_BODY()

	public:
		virtual void FireMain() = 0;
		virtual void FireSecond() = 0;
		
		virtual void RotateTurretYAxis() = 0;

		//virtual void InvalidateTurret() = 0; doesnt work because of tank turrets changing system
};
