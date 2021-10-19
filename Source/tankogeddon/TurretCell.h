#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "TurretCell.generated.h"

class UImage;
class ATowerBodyBase;
class ATankPlayerController;


UCLASS()
class TANKOGEDDON_API UTurretCell : public UUserWidget{
	GENERATED_BODY()

	DECLARE_DYNAMIC_DELEGATE_OneParam(FCreateDraggableActor, TSubclassOf<ATowerBodyBase>, TurretClass);
	DECLARE_DYNAMIC_DELEGATE_OneParam(FShowPopUp, FName, TurretName);
	DECLARE_DYNAMIC_DELEGATE(FHidePopUp);

	public:
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (BindWidget))
		UImage* Thumbnail;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		FName TurretName;

		FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
		void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
		bool NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
		bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
		void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
		void NativeOnMouseLeave(const FPointerEvent& InMouseEvent);


		UFUNCTION()
		FName GetTurretName();

		UFUNCTION()
		void OnDragCancelledHandle(UDragDropOperation* Operation);

		void SetDraggable(bool bState);

		FCreateDraggableActor CreateDraggableActor;

		FShowPopUp ShowPopUp;
		FHidePopUp HidePopUp;

	protected:
		UPROPERTY(EditAnywhere)
		TSubclassOf<ATowerBodyBase> DraggedTurretClass;

	private:
		bool bIsDraggable;
};
