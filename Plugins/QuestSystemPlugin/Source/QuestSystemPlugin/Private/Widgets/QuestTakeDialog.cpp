#include "Widgets/QuestTakeDialog.h"
#include "Widgets/QuestDescriptionWidget.h"
#include "Core/Quest.h"
#include "Core/QuestManager.h"

#include "Components/Button.h"


void UQuestTakeDialog::Init(UQuest* QuestToBind) {
	if(!QuestToBind || !QuestDescription)
		return;

	BindedQuest = QuestToBind;
	QuestDescription->Init(BindedQuest);
}

UQuest* UQuestTakeDialog::GetBindedQuest() const {
	return BindedQuest;
}

void UQuestTakeDialog::NativeConstruct() {
	Super::NativeConstruct();

	AcceptButton->OnClicked.AddDynamic(this, &UQuestTakeDialog::OnAcceptButtonPressed);
	DiscardButton->OnClicked.AddDynamic(this, &UQuestTakeDialog::OnDiscardButtonPressed);
}

void UQuestTakeDialog::OnAcceptButtonPressed() {
	if(OnApply.IsBound())
		OnApply.Broadcast(BindedQuest);

	RemoveFromParent();
}

void UQuestTakeDialog::OnDiscardButtonPressed() {
	RemoveFromParent();
}