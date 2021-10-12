#include "Styling/CoreStyle.h"
#include "MainMenuWidgetStyle.h"


FMainMenuStyle::FMainMenuStyle(){
	MainButtonsStyle = FCoreStyle::Get().GetWidgetStyle<FButtonStyle>("Button");
	SettingsButtonsStyle = FCoreStyle::Get().GetWidgetStyle<FButtonStyle>("Button");

	// MainTextBlockStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("TextBlock");
	// SettingsTextBlockStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("TextBlock");
}

FMainMenuStyle::~FMainMenuStyle(){
}

const FName FMainMenuStyle::TypeName(TEXT("FMainMenuStyle"));

const FMainMenuStyle& FMainMenuStyle::GetDefault(){
	static FMainMenuStyle Default;
	return Default;
}

void FMainMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const{
	SettingsButtonsStyle.GetResources(OutBrushes);
	MainButtonsStyle.GetResources(OutBrushes);

	// MainTextBlockStyle.GetResources(OutBrushes);
	// SettingsTextBlockStyle.GetResources(OutBrushes);

	OutBrushes.Add(&GameIcon);
}

