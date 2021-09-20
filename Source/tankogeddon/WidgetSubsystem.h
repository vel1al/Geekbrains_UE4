// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameStructs.h"
#include "WidgetSubsystem.generated.h"


class UUserWidget;

UCLASS()
class TANKOGEDDON_API UWidgetSubsystem : public UGameInstanceSubsystem{
	GENERATED_BODY()
	
	public:
		bool AddWidgetToViewport(EWidget RequiredWidget, int ZOrder = 0);

		bool RemoveWidgetFromViewport(EWidget RequiredWidget);
		bool DeleteWidget(EWidget RequiredWidget);

		UUserWidget* CreateWidget(EWidget RequiredWidget);

	protected:
		UPROPERTY(EditAnywhere)
    	TMap<EWidget, TSubclassOf<UUserWidget>> DefaultWidgetClases;

		virtual void BeginDestroy() override;

	private:
		TMap<UUserWidget*, EWidget> AllocatedWidgets;
		TMap<UUserWidget*, EWidget> ViewportWidgets;
};