#include "StylesSet.h"
#include "Engine.h"
#include "SlateBasics.h"
#include "Slate/SlateGameResources.h"
#include "Styling/ISlateStyle.h"


TSharedPtr<ISlateStyle> FindStyle(const FString& ScopeToDirectory){
    TSharedPtr<FSlateGameResources> Style = FSlateGameResources::New(FName("StyleSet"), ScopeToDirectory, ScopeToDirectory);

    return Style;
}

TSharedPtr<ISlateStyle> FStyleSet::StylePtr = nullptr;

void FStyleSet::Initialize(){
    Shutdown();

    StylePtr = FindStyle("/Game/Blueprints/Widgets/Styles");
    FSlateStyleRegistry::RegisterSlateStyle(*StylePtr);
}

void FStyleSet::Shutdown(){
    if (StylePtr.IsValid()){
		FSlateStyleRegistry::UnRegisterSlateStyle(*StylePtr);
		ensure(StylePtr.IsUnique());
		StylePtr.Reset();
    }
}

const ISlateStyle& FStyleSet::Get(){
    if (!StylePtr.IsValid())
    	Initialize();
       
    return *StylePtr;
}