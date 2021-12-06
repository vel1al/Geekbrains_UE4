#include "Widgets/QuestJournalElementWidget.h"
#include "Core/Quest.h"

#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/RichTextBlock.h"


void UQuestJournalElementWidget::Init(UQuest* QuestToBind) {
	if(!QuestToBind)
		return;

	BindedQuest = QuestToBind;
	QuestName->SetText(BindedQuest->Name);

	SetActive(false);
}

void UQuestJournalElementWidget::SetActive(bool bState) {
	bActive = bState;

	if(bActive)
		OnMarkedImage->SetVisibility(ESlateVisibility::Hidden);
	else
		OnMarkedImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

bool UQuestJournalElementWidget::GetActive() const {
	return bActive;
}

UQuest* UQuestJournalElementWidget::GetBindedQuest() const {
	return BindedQuest;
}

void UQuestJournalElementWidget::NativeConstruct() {
	Super::NativeConstruct();

	WidgetButton->OnClicked.AddDynamic(this, &UQuestJournalElementWidget::UQuestJournalElementWidget::OnClickedBridge);
}

void UQuestJournalElementWidget::OnClickedBridge() {
	if(OnQuestClicked.IsBound())
		OnQuestClicked.Broadcast(BindedQuest);
}
