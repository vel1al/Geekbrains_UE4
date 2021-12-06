#include "Core/ObjectiveAssetAction.h"

#include "Core/Quest.h"
#include "Developer/AssetTools/Public/AssetTypeCategories.h"


FText FObjectiveAssetAction::GetName() const{
	return FText::FromString("Quest");
}

FColor FObjectiveAssetAction::GetTypeColor() const{
	return FColor::Cyan;
}

UClass* FObjectiveAssetAction::GetSupportedClass() const{
	return UQuest::StaticClass();
}

uint32 FObjectiveAssetAction::GetCategories(){
	return EAssetTypeCategories::Misc | EAssetTypeCategories::Basic;
}

void FObjectiveAssetAction::RegisterChanges(){
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FObjectiveAssetAction));
}