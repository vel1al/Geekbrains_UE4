#include "Widgets/QuestHUD.h"
#include "Core/Quest.h"
#include "Widgets/ObjectiveDescriptionWidget.h"

#include "Components/RichTextBlock.h"
#include "Components/VerticalBox.h"


void UQuestHUD::Init(UQuest* QuestToBind) {
	if(!QuestToBind || !ObjectiveDescriptionWidgetClass){
		SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	BindedQuest = QuestToBind;
	QuestName->SetText(BindedQuest->Name);
	ObjectivesVerticalBox->ClearChildren();

	TArray<UObjective*> QuestObjectives = BindedQuest->GetObjectives();
	for(auto Objective : QuestObjectives) {
		if(!Objective)
			return;

		UObjectiveDescriptionWidget* ObjectiveDescriptionWidget = CreateWidget<UObjectiveDescriptionWidget>(this, ObjectiveDescriptionWidgetClass);
		ObjectiveDescriptionWidget->Init(Objective);

		ObjectivesVerticalBox->AddChild(ObjectiveDescriptionWidget);
	}
}

UQuest* UQuestHUD::GetBindedQuest() const {
	return BindedQuest;
}