// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "tankogeddon/Game/Misc/GameStructs.h"

#include "TankHUD.generated.h"

class UUserWidget;
class UWidgetSubsystem;


UCLASS()
class TANKOGEDDON_API ATankHUD : public AHUD{
	GENERATED_BODY()

	public:
		void SetActiveWidget(EWidget RequiredWidget, bool bState);
	
	protected:
		virtual void BeginPlay() override;

		UWidgetSubsystem* WidgetSubsystem;
		TMap<EWidget, UUserWidget*> AllocatedWidgets;
};
