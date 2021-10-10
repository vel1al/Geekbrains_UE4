#include "MinimapWidget.h"
#include "TankGameModeBase.h"


UMinimapWidget::UMinimapWidget(){
    PlayerPositionGetter.BindUObject(this, &UMinimapWidget::GetPlayerLocation);
    CenteringToPlayerGetter.BindUObject(this, &UMinimapWidget::GetCenteringToPlayer);
	SizeAdjustmentGetter.BindUObject(this, &UMinimapWidget::GetSizeAdjustment);
}

void UMinimapWidget::ReleaseSlateResources(bool bReleaseChildren){
    Super::ReleaseSlateResources(bReleaseChildren);

    AllocatedMiniMap.Reset();
}

void UMinimapWidget::SynchronizeProperties(){
	Super::SynchronizeProperties();

    AllocatedMiniMap->PlayerPosition.Bind(PlayerPositionGetter);
    AllocatedMiniMap->bIsCenteringToPlayer.Bind(CenteringToPlayerGetter);
    AllocatedMiniMap->SizeAdjustment.Bind(SizeAdjustmentGetter);
}

FVector2D UMinimapWidget::GetPlayerLocation(){
    FVector PlayerLocation = FVector(0.f);
    if(GetWorld()->GetFirstPlayerController())
        PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

    return FVector2D(PlayerLocation.X, PlayerLocation.Y);
}

bool UMinimapWidget::GetCenteringToPlayer(){
    return bIsCenteringToPlayer;
}

float UMinimapWidget::GetSizeAdjustment(){
    return SizeAdjustment;
}

TSharedRef<SWidget> UMinimapWidget::RebuildWidget(){
    ATankGameModeBase* GameMode = Cast<ATankGameModeBase>(GetWorld()->GetAuthGameMode());

    TArray<FObstacle> Obstacles;
    if(GameMode)
        Obstacles = GameMode->GetDefaultObstacles();
    else
        Obstacles = TArray<FObstacle>();

    AllocatedMiniMap = SNew(SMiniMapWidget)
        .PlayerSign(PlayerSign)
        .BorderTexture(BorderTexture)
        .OutlineTexture(OutlineTexture)
        .Obstacles(Obstacles)
        .TopLeftCorner(TopLeftCorner)
        .BottomRightCorner(BottomRightCorner)
        .MapTopLeftCorner(MapTopLeftCorner)
        .MapBottomRightCorner(MapBottomRightCorner);

    return AllocatedMiniMap.ToSharedRef();
}