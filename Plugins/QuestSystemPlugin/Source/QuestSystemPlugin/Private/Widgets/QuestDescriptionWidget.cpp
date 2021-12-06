#include "Widgets/QuestDescriptionWidget.h"
#include "Core/Quest.h"
#include "Widgets/ObjectiveDescriptionWidget.h"

#include "Components/RichTextBlock.h"
#include "Components/ScrollBox.h"


void UQuestDescriptionWidget::Init(UQuest* QuestToBind) {
	if(!QuestToBind || !ObjectiveDescriptionWidgetClass) {
		SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	
	BindedQuest = QuestToBind;
	QuestName->SetText(BindedQuest->Name);
	ObjectivesScrollBox->ClearChildren();
	
	TArray<UObjective*> QuestObjectives = BindedQuest->GetObjectives();
	for(auto Objective : QuestObjectives) {
		if(!Objective)
			continue;

		UObjectiveDescriptionWidget* ObjectiveDescriptionWidget = CreateWidget<UObjectiveDescriptionWidget>(this, ObjectiveDescriptionWidgetClass);
		ObjectiveDescriptionWidget->Init(Objective);

		ObjectivesScrollBox->AddChild(ObjectiveDescriptionWidget);
	}
}

UQuest* UQuestDescriptionWidget::GetBindedQuest() const {
	return BindedQuest;
}