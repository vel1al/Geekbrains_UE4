#include "SMinimapWidget.h"
#include "SlateOptMacros.h"
#include "GenericPlatform/GenericPlatformMath.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMiniMapWidget::Construct(const FArguments& InArgs){	
	PlayerSign = InArgs._PlayerSign;
	BorderTexture = InArgs._BorderTexture;
	OutlineTexture = InArgs._OutlineTexture;
	
	TopLeftCorner =	InArgs._TopLeftCorner;
	BottomRightCorner = InArgs._BottomRightCorner;
	
	Obstacles = InArgs._Obstacles;

	MapBottomRightCorner = InArgs._MapBottomRightCorner;
	MapTopLeftCorner = InArgs._MapTopLeftCorner;

	PlayerPosition = InArgs._PlayerPosition.Get();

	bIsCenteringToPlayer = InArgs._bIsCenteringToPlayer.Get();
	SizeAdjustment = InArgs._SizeAdjustment.Get();


	for(auto& obstacle : Obstacles){
		FObstacle LocalSizeObstacle;

		LocalSizeObstacle.Color = obstacle.Color;

		for(auto& point : obstacle.Points)
			LocalSizeObstacle.Points.Add(ConvertWorldToLocalLocation(point));

		LocalSizedObstacles.Add(LocalSizeObstacle);
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FVector2D SMiniMapWidget::ConvertWorldToLocalLocation(FVector2D WorldLocation) const {
	if(bIsCenteringToPlayer.Get()){
		return FVector2D(0.f);
	}
	else{
		FVector2D First = (WorldLocation - MapTopLeftCorner);
		FVector2D Second = (MapTopLeftCorner + MapBottomRightCorner);
		FVector2D Ratio = First/Second;

		return FVector2D(FMath::Clamp(FMath::Lerp(TopLeftCorner, BottomRightCorner, Ratio), TopLeftCorner, BottomRightCorner));
	}
}

int32 SMiniMapWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
					    int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const{
	FVector2D LocalSize = AllottedGeometry.GetLocalSize();

	FGeometry MiniMapBoxGeometry = AllottedGeometry;
	
	FSlateBrush BorderBrush;
	FSlateBrush OutlineBrush;
	
	BorderBrush.SetResourceObject(BorderTexture);
	OutlineBrush.SetResourceObject(OutlineTexture);

	FSlateDrawElement::MakeBox(
			OutDrawElements, 
			LayerId, 
			MiniMapBoxGeometry.ToPaintGeometry(TopLeftCorner, BottomRightCorner),
			&BorderBrush
	);
	
	FSlateDrawElement::MakeBox(
			OutDrawElements, 
			++LayerId, 
			MiniMapBoxGeometry.ToPaintGeometry(TopLeftCorner, BottomRightCorner),
			&OutlineBrush
	);

	for(auto& obstacle : LocalSizedObstacles){
		FSlateDrawElement::MakeLines(
			OutDrawElements,
			LayerId,
			AllottedGeometry.ToPaintGeometry(),
			obstacle.Points,
			obstacle.Color
		);
	}

	FSlateBrush PlayerBrush;
	PlayerBrush.SetResourceObject(PlayerSign); 

	FSlateDrawElement::MakeBox(
		OutDrawElements,
		++LayerId,
		AllottedGeometry.ToPaintGeometry(ConvertWorldToLocalLocation(PlayerPosition.Get()), PlayerBrush.ImageSize),
		&PlayerBrush
	);

	return 0;
}