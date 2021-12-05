#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "tankogeddon/Game/Misc/GameStructs.h"

#include "WidgetSubsystem.generated.h"

class ATankGameModeBase;
class UUserWidget;


UCLASS()
class TANKOGEDDON_API UWidgetSubsystem : public UGameInstanceSubsystem{
	GENERATED_BODY()
	
	public:
		bool AddWidgetToViewport(EWidget RequiredWidget, int ZOrder = 0);
	
		bool RemoveWidgetFromViewport(EWidget RequiredWidget);
		bool DeleteWidget(EWidget RequiredWidget);

		void ToggleWidgetVisibility(EWidget Widget, const bool bState);
	
		UUserWidget* AllocateWidget(EWidget RequiredWidget);

	protected:
		//virtual void BeginDestroy() override;

	private:
		void UpdateGameModeRef();

    	ATankGameModeBase* CurrentGameMode;
		TMap<EWidget, UUserWidget*> AllocatedWidgets;
		TMap<EWidget, UUserWidget*> ViewportWidgets;
};
