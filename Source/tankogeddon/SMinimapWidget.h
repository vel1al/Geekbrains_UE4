#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MiniMapWidgetStyle.h"
#include "GameStructs.h"


class UTexture2D;


class TANKOGEDDON_API SMiniMapWidget : public SCompoundWidget{
	public:
		SLATE_BEGIN_ARGS(SMiniMapWidget): 
			_TopLeftCorner(FVector2D::ZeroVector),
			_BottomRightCorner(FVector2D::ZeroVector),
			_bIsCenteringToPlayer(true),
			_SizeAdjustment(0),
			_MapBottomRightCorner(FVector2D::ZeroVector),
			_MapTopLeftCorner(FVector2D::ZeroVector),
			_PlayerPosition(FVector2D::ZeroVector)
		{}
		
		// SLATE_ARGUMENT(UTexture2D*, PlayerSign)
		// SLATE_ARGUMENT(UTexture2D*, BorderTexture)
		// SLATE_ARGUMENT(UTexture2D*, OutlineTexture)

		SLATE_ARGUMENT(FVector2D, TopLeftCorner)
		SLATE_ARGUMENT(FVector2D, BottomRightCorner)

		SLATE_ARGUMENT(TArray<FFigure>, Figures)

		SLATE_ARGUMENT(FVector2D, MapBottomRightCorner)
		SLATE_ARGUMENT(FVector2D, MapTopLeftCorner)

		SLATE_ATTRIBUTE(FVector2D, PlayerPosition)

		SLATE_ATTRIBUTE(bool, bIsCenteringToPlayer)
		SLATE_ATTRIBUTE(float, SizeAdjustment)

		SLATE_STYLE_ARGUMENT(FMiniMapStyle, Style)

		SLATE_END_ARGS()

	
		void Construct(const FArguments& InArgs);

		virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, 
							int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	
		TAttribute<FVector2D> PlayerPosition;
		TAttribute<bool> bIsCenteringToPlayer;
		TAttribute<float> SizeAdjustment;

	protected:
		FVector2D ConvertWorldToLocalLocation(FVector2D WorldLocation) const;

		const FMiniMapStyle* MiniMapStyle;

		// UTexture2D* PlayerSign;
		// UTexture2D* BorderTexture;
		// UTexture2D* OutlineTexture;

		FVector2D TopLeftCorner;
		FVector2D BottomRightCorner;

		FVector2D MapTopLeftCorner;
		FVector2D MapBottomRightCorner;

		TArray<FFigure> Figures;

	private:
		TArray<FObstacle> LocalSizedObstacles;
};