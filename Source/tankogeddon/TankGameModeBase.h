#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Widget.h"
#include "GameStructs.h"

#include "TankGameModeBase.generated.h"

class UUserWidget;


UCLASS()
class TANKOGEDDON_API ATankGameModeBase : public AGameModeBase{
	GENERATED_BODY()
	
	public:
		void PlayerDie();

		UFUNCTION(BlueprintImplementableEvent)
		void OnPlayerDieEvent();

		TSubclassOf<UUserWidget> GetDefaultClass(EWidget Key); 
		TArray<FFigure> GetDefaultFigures();

	protected:
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    	TMap<EWidget, TSubclassOf<UUserWidget>> DefaultWidgetClases;

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TArray<FFigure> DefaultFigures;
};
