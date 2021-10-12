#include "MiniMapWidgetStyle.h"

FMiniMapStyle::FMiniMapStyle(){
	return;
}

FMiniMapStyle::~FMiniMapStyle(){
	return;
}

const FName FMiniMapStyle::TypeName(TEXT("FMiniMapStyle"));

const FMiniMapStyle& FMiniMapStyle::GetDefault(){
	static FMiniMapStyle Default;
	return Default;
}

void FMiniMapStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const{
	OutBrushes.Add(&MapBrush);
	OutBrushes.Add(&MapBorderBrush);
	OutBrushes.Add(&PlayerBrush);
}

