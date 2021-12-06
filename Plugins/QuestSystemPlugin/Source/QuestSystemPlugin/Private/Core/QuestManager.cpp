#include "QuestSystemPlugin/Public/Core/QuestManager.h"
#include "QuestSystemPlugin/Public/Widgets/QuestTakeDialog.h"
#include "QuestSystemPlugin/Public/Widgets/QuestHUD.h"

#include "QuestSystemPlugin/Public/Core/Quest.h"
#include "Widgets/QuestJournalWidget.h"


void UQuestManager::TakeQuest(UQuest* Quest) {
	if(TakenQuestsList.Contains(Quest))
		return;
	
	TakenQuestsList.AddUnique(Quest);
	SetActiveQuest(Quest, true);
	Quest->Init(this, BindedPlayer);

	if(OnQuestTaken.IsBound())
		OnQuestTaken.Broadcast(Quest);
}

void UQuestManager::DiscardQuest(UQuest* Quest) {
	if(!TakenQuestsList.Contains(Quest))
		return;

	TakenQuestsList.Remove(Quest);

	if(OnQuestDiscard.IsBound())
		OnQuestDiscard.Broadcast(Quest);
}

void UQuestManager::Init(const FQuestManagerInitializer& QuestManagerInitializer) {
	BindedPlayer = QuestManagerInitializer.PlayerToBind;
	
	BindedQuestJournalWidget = Cast<UQuestJournalWidget>(QuestManagerInitializer.QuestJournalWidgetToBind);
	BindedQuestHUD = Cast<UQuestHUD>(QuestManagerInitializer.QuestHUDToBind);
	
	QuestDelegates = QuestManagerInitializer.QuestDelegatesToBind;
	
	QuestTakeDialogClass = QuestManagerInitializer.QuestTakeDialogClassToBind;

	BindedQuestJournalWidget->OnQuestFocusChange.AddUObject(this, &UQuestManager::OnQuestFocusChanged);
}

void UQuestManager::CallQuestTakeDialog(UQuest* Quest) {
	UQuestTakeDialog* QuestTakeDialog = CreateWidget<UQuestTakeDialog>(GetWorld(), QuestTakeDialogClass);
	
	QuestTakeDialog->Init(Quest);
	QuestTakeDialog->OnApply.AddUObject(this, &UQuestManager::TakeQuest);
	QuestTakeDialog->AddToViewport();
}

TArray<UQuest*> UQuestManager::GetTakenQuests() const {
	return TakenQuestsList;
}

void UQuestManager::OnQuestFocusChanged(UQuest* Quest) {
	if(BindedQuestHUD)
		BindedQuestHUD->Init(Quest);
}

void UQuestManager::SetActiveQuest(UQuest* QuestToActive, const bool bState) {
	int32 LocalStoredQuest = TakenQuestsList.Find(QuestToActive);

	SetActiveQuest(LocalStoredQuest, bState);
}

void UQuestManager::SetActiveQuest(const int32 LocalIndex, const bool bState) {
	if(!TakenQuestsList.IsValidIndex(LocalIndex))
		return;

	TakenQuestsList[LocalIndex]->ToggleQuestState(bState);
}