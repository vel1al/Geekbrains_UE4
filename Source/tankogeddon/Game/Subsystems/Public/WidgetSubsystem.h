#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "tankogeddon/Game/Misc/GameStructs.h"

#include "WidgetSubsystem.generated.h"

class UUserWidget;


UCLASS()
class TANKOGEDDON_API UWidgetSubsystem : public UGameInstanceSubsystem{
	GENERATED_BODY()
	
	public:
		void Init(TMap<EWidget, TSubclassOf<UUserWidget>> WidgetClassesToBind);
	
		bool AddWidgetToViewport(EWidget RequiredWidget, int ZOrder = 0);
	
		bool RemoveWidgetFromViewport(EWidget RequiredWidget);
		bool DeleteWidget(EWidget RequiredWidget);
	
		void SetActiveWidget(EWidget RequiredWidget, bool bState);
	
		UUserWidget* AllocateWidget(EWidget RequiredWidget);
		UUserWidget* GetAllocatedWidget(EWidget RequiredWidget) const;
		
	protected:
		TMap<EWidget, TSubclassOf<UUserWidget>> WidgetClasses;
		TMap<EWidget, UUserWidget*> AllocatedWidgets;
};
