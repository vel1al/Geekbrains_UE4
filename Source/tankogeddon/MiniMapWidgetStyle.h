#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "Styling/SlateBrush.h"
#include "Math/Color.h"

#include "MiniMapWidgetStyle.generated.h"


USTRUCT()
struct TANKOGEDDON_API FMiniMapStyle : public FSlateWidgetStyle{
	GENERATED_USTRUCT_BODY()

	FMiniMapStyle();
	virtual ~FMiniMapStyle();
	
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMiniMapStyle& GetDefault();


	UPROPERTY(EditAnywhere,Category = "Brushes")
	FSlateBrush MapBrush;
	UPROPERTY(EditAnywhere,Category = "Brushes")
	FSlateBrush MapBorderBrush;
	UPROPERTY(EditAnywhere,Category = "Brushes")
	FSlateBrush PlayerBrush;

	UPROPERTY(EditAnywhere, Category = "Colors")
	FLinearColor LinesColor;
};

UCLASS(hidecategories=Object, MinimalAPI)
class UMiniMapWidgetStyle : public USlateWidgetStyleContainerBase{
		GENERATED_BODY()

	public:
		UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
		FMiniMapStyle WidgetStyle;

		virtual const struct FSlateWidgetStyle* const GetStyle() const override{
			return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
		}
};
