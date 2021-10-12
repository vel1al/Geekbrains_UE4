#include "MinimapWidget.h"
#include "MiniMapWidgetStyle.h"
#include "TankGameModeBase.h"
#include "StylesSet.h"


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

FMiniMapStyle UMinimapWidget::GetMiniMapStyle(ETheme theme){
    FMiniMapStyle ReturnValue;
    
    switch(theme){
        case ETheme::Bright:    ReturnValue = FStyleSet::Get().GetWidgetStyle<FMiniMapStyle>("Bright_MiniMapStyle");
        break;
        case ETheme::Dark:      ReturnValue = FStyleSet::Get().GetWidgetStyle<FMiniMapStyle>("Dark_MiniMapStyle");
        break;
        default:                ReturnValue = FStyleSet::Get().GetWidgetStyle<FMiniMapStyle>("Default_MiniMapStyle");
        break;
    }

    return ReturnValue;
}

TSharedRef<SWidget> UMinimapWidget::RebuildWidget(){
    ATankGameModeBase* GameMode = Cast<ATankGameModeBase>(GetWorld()->GetAuthGameMode());

    MiniMapStyle = GetMiniMapStyle(WidgetTheme);

    TArray<FFigure> Figures;
    if(GameMode)
        Figures = GameMode->GetDefaultFigures();
    else
        Figures = TArray<FFigure>();

    AllocatedMiniMap = SNew(SMiniMapWidget)
        // .PlayerSign(PlayerSign)
        // .BorderTexture(BorderTexture)
        // .OutlineTexture(OutlineTexture)
        .Figures(Figures)
        .TopLeftCorner(TopLeftCorner)
        .BottomRightCorner(BottomRightCorner)
        .MapTopLeftCorner(MapTopLeftCorner)
        .MapBottomRightCorner(MapBottomRightCorner)
        .Style(&MiniMapStyle);

    return AllocatedMiniMap.ToSharedRef();
}