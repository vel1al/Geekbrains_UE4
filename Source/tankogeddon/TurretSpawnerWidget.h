#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "TurretSpawnerWidget.generated.h"

class ATankPlayerController;
class UHorizontalBox;
class ATowerBodyBase;
class UTurretPopUp;
class UTurretCell;


UCLASS()
class TANKOGEDDON_API UTurretSpawnerWidget : public UUserWidget{
	GENERATED_BODY()

	public:
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (BindWidget))
		UHorizontalBox* HorizontalBoxWidget;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (BindWidget))
		UTurretPopUp* PopUp;

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		int32 CellsCount;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		float MaxDraggingDistantion;

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TSubclassOf<UTurretCell> DefaultTurretCellClass;

		virtual void NativeConstruct() override;
    	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

		void SetEditingMode(bool bState);
		
		UFUNCTION()
		void ShowPopUp(FName RequiredTurret);
		UFUNCTION()
		void HidePopUp();

		UFUNCTION()
		void CreateDraggableActor(TSubclassOf<ATowerBodyBase> TurretClass);
		UFUNCTION()
		void StopDraggingTurret();

	protected:
		UPROPERTY()
		ATankPlayerController* TankPlayerController;

	private:
		TArray<UTurretCell*> TurretCells;

		ATowerBodyBase* DraggedTurret = nullptr;

		bool bIsDragging = false;
};
