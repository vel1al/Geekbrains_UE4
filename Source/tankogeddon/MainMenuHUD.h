#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "MainMenuHUD.generated.h"

class UMainMenuWidget;


UCLASS()
class TANKOGEDDON_API AMainMenuHUD : public AHUD{
	GENERATED_BODY()
	
	protected:
		virtual void BeginPlay() override;
		//virtual void BeginDestroy() override;

	private:
		void OnClosingMenu();

		UMainMenuWidget* AllocatedMainMenu;
};
