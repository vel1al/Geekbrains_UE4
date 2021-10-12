#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "Styling/SlateBrush.h"

#include "MainMenuWidgetStyle.generated.h"


USTRUCT()
struct TANKOGEDDON_API FMainMenuStyle : public FSlateWidgetStyle{
	GENERATED_USTRUCT_BODY()

	FMainMenuStyle();
	virtual ~FMainMenuStyle();
	
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMainMenuStyle& GetDefault();

	UPROPERTY(EditAnywhere, Category = "Appearance|Buttons")
	FButtonStyle MainButtonsStyle;
	UPROPERTY(EditAnywhere, Category = "Appearance|Buttons")
    FButtonStyle SettingsButtonsStyle;

	// UPROPERTY(EditAnywhere, Category = "Appearance|TextBlocks")
	// FTextBlockStyle MainTextBlockStyle;
	// UPROPERTY(EditAnywhere, Category = "Appearance|TextBlocks")
	// FTextBlockStyle SettingsTextBlockStyle;

	UPROPERTY(EditAnywhere, Category = "Appearance|Images")
	FSlateBrush GameIcon;
};


UCLASS(hidecategories=Object, MinimalAPI)
class UMainMenuWidgetStyle : public USlateWidgetStyleContainerBase{
	GENERATED_BODY()

public:
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMainMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
