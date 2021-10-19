#include "TurretSpawnerWidget.h"

#include "TowerBodyBase.h"
#include "TankPlayerController.h"
#include "TurretCell.h"
#include "Components/HorizontalBox.h"
#include "TurretPopUp.h"

#include "Components/Image.h"

#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"


void UTurretSpawnerWidget::NativeConstruct() {
    Super::NativeConstruct();

    if(HorizontalBoxWidget){
        for(int Cell = 0; Cell < CellsCount; ++Cell){
            UTurretCell* TurretCell = CreateWidget<UTurretCell>(this, DefaultTurretCellClass);

            TurretCell->SetDraggable(true);
            
            TurretCell->Thumbnail->SetColorAndOpacity(FLinearColor(0.1 * Cell, 0.1 * Cell, 0.1 * Cell, 1));

            TurretCell->CreateDraggableActor.BindDynamic(this, &UTurretSpawnerWidget::CreateDraggableActor);
            TurretCell->ShowPopUp.BindDynamic(this, &UTurretSpawnerWidget::ShowPopUp);
            TurretCell->HidePopUp.BindDynamic(this, &UTurretSpawnerWidget::HidePopUp);

            HorizontalBoxWidget->AddChildToHorizontalBox(TurretCell);

            TurretCells.Add(TurretCell);
        }
    }

    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    TankPlayerController = Cast<ATankPlayerController>(PlayerController);

    TankPlayerController->OnMouseButtonUp.AddDynamic(this, &UTurretSpawnerWidget::StopDraggingTurret);
}

void UTurretSpawnerWidget::ShowPopUp(FName RequiredTurret){
    if(PopUp){
        PopUp->SetData(RequiredTurret);
        PopUp->SetVisibility(ESlateVisibility::HitTestInvisible);
    }
}

void UTurretSpawnerWidget::HidePopUp(){
    if(PopUp)
        PopUp->SetVisibility(ESlateVisibility::Collapsed);
}

void UTurretSpawnerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
    Super::NativeTick(MyGeometry, InDeltaTime);

    if(!bIsDragging)
        return;
    if(!DraggedTurret && !TankPlayerController)
        return;


   	FVector WorldMouseLocation;
   	FVector WorldMouseDirection;
   	
    TankPlayerController->DeprojectMousePositionToWorld(WorldMouseLocation, WorldMouseDirection);

    //DrawDebugLine(GetWorld(), WorldMouseLocation, WorldMouseDirection * MaxDraggingDistantion, FColor::Emerald, true, 1, 0, 10);

   	FHitResult HitResult;
   	GetWorld()->LineTraceSingleByChannel(
   		HitResult,
   		WorldMouseLocation,
   		WorldMouseLocation + WorldMouseDirection * MaxDraggingDistantion,
   		ECollisionChannel::ECC_WorldStatic
    );

    if(HitResult.Actor.Get())
   	    DraggedTurret->SetActorLocation(HitResult.Location);
}

void UTurretSpawnerWidget::SetEditingMode(bool bState){
    for(auto cell : TurretCells)
        cell->SetDraggable(bState);
}

void UTurretSpawnerWidget::StopDraggingTurret() {
    DraggedTurret = nullptr;
    bIsDragging = false;
}

void UTurretSpawnerWidget::CreateDraggableActor(TSubclassOf<ATowerBodyBase> TurretClass) {
    DraggedTurret = GetWorld()->SpawnActorDeferred<ATowerBodyBase>(TurretClass, FTransform(), nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
    UGameplayStatics::FinishSpawningActor(DraggedTurret, FTransform());

    bIsDragging = true;
}