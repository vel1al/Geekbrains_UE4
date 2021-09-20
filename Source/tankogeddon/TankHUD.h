// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameStructs.h"
#include "TankHUD.generated.h"

class UUserWidget; 


UCLASS()
class TANKOGEDDON_API ATankHUD : public AHUD{
	GENERATED_BODY()
	
	public:
		void SetActivePauseMenu(bool bActive);
		void SetActiveHUD(bool bActive);
		void SetActiveGaveOver(bool bActive);

	protected:
		virtual void BeginPlay() override;
		virtual void EndPlay() override;

	private:
		void OnGameOverEnabling();

		TMap<EWidget, UUSerWidget*> AllocatedWidgets;
};
