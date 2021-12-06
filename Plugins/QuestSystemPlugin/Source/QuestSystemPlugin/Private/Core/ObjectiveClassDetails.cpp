#include "Core/ObjectiveClassDetails.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Editor/PropertyEditor/Public/PropertyEditorModule.h"


#define LOCTEXT_NAMESPACE "QuestSystemPlugin" 


TSharedRef<IDetailCustomization> FObjectiveClassDetails::MakeInstance(){
	return MakeShareable(new FObjectiveClassDetails);
}

void FObjectiveClassDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) {
	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory("Quest", FText::GetEmpty(), ECategoryPriority::Important);

	UQuest* ControllingQuest = nullptr;

	TArray<TWeakObjectPtr<UObject>> ControllingObjects;
	DetailBuilder.GetObjectsBeingCustomized(ControllingObjects);

	for(auto Object : ControllingObjects) {
		if(Object.IsValid()) {
			ControllingQuest = Cast<UQuest>(Object);
			if(ControllingQuest)
				break;
		}
	}
	check(ControllingQuest);

	Category.AddCustomRow(LOCTEXT("RowName", "ObjectivesInstances"))
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ContentName", "Create objectives instances"))
			//.Font(IDetailLayoutBuilder::GetDetailFont())
		]
		.ValueContent()
		[
			SNew(SButton)
			.HAlign(HAlign_Center)
			.OnClicked_UObject(ControllingQuest, &UQuest::CreateObjectivesInstances)
		];
}

void FObjectiveClassDetails::RegisterChanges(){
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	PropertyModule.RegisterCustomClassLayout("Quest", FOnGetDetailCustomizationInstance::CreateStatic(&FObjectiveClassDetails::MakeInstance));
}