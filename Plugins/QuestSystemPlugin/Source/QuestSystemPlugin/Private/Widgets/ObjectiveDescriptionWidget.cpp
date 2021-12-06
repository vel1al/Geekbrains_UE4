#include "Widgets/ObjectiveDescriptionWidget.h"
#include "Objectives/Objective.h"

#include "Components/RichTextBlock.h"


void UObjectiveDescriptionWidget::Init(UObjective* ObjectiveToBind) {
	if(!ObjectiveToBind)
		return;

	BindedObjective = ObjectiveToBind;
	ObjectiveDescription->SetText(BindedObjective->GetDescription());
}

UObjective* UObjectiveDescriptionWidget::GetBindedObjective() const {
	return BindedObjective;
}