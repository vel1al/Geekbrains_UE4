#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "TurretPopUp.generated.h"

class UDataTable;
class UTextBlock;
class UImage;


UCLASS()
class TANKOGEDDON_API UTurretPopUp : public UUserWidget{
	GENERATED_BODY()

	public:
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		UDataTable* TurretPopUpDataTable;

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (BindWidget))
		UTextBlock* TextDescription;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (BindWidget))
		UImage* Thumbnail;

		void SetData(FName RequiredTurret);
};
