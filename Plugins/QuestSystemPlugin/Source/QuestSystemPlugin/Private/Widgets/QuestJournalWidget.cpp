#include "Widgets/QuestJournalWidget.h"

#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Core/QuestManager.h"

#include "Widgets/QuestHUD.h"
#include "Widgets/QuestJournalElementWidget.h"
#include "Widgets/QuestDescriptionWidget.h"


void UQuestJournalWidget::NativeConstruct() {
	Super::NativeConstruct();

	BindedQuestManager = GetWorld()->GetGameInstance()->GetSubsystem<UQuestManager>();
	if(!BindedQuestManager)
		return;

	TArray<UQuest*> TakenQuests = BindedQuestManager->GetTakenQuests();
	for(auto Quest : TakenQuests)
		if(Quest)
			OnQuestTaken(Quest);

	BindedQuestManager->OnQuestTaken.AddUObject(this, &UQuestJournalWidget::OnQuestTaken);
	BindedQuestManager->OnQuestDiscard.AddUObject(this, &UQuestJournalWidget::OnQuestDiscarded);
	MarkButton->OnClicked.AddDynamic(this, &UQuestJournalWidget::UQuestJournalWidget::OnMarkButtonPressed);
	DiscardButton->OnClicked.AddDynamic(this, &UQuestJournalWidget::UQuestJournalWidget::OnDiscardButtonPressed);
}

void UQuestJournalWidget::RefreshChildrens() {
	ActiveQuestVerticalBox->ClearChildren();

	for(auto QuestJournalElementWidget : QuestJournalElementWidgets)
		if(QuestJournalElementWidget)
			ActiveQuestVerticalBox->AddChildToVerticalBox(QuestJournalElementWidget);
}

void UQuestJournalWidget::ChangeQuestFocus(UQuest* Quest) {
	QuestDescription->Init(Quest);
}

void UQuestJournalWidget::OnDiscardButtonPressed() {
	UQuest* BindedQuest = QuestDescription->GetBindedQuest();
	if(!BindedQuest)
		return;

	ChangeQuestFocus(nullptr);
	BindedQuestManager->DiscardQuest(BindedQuest);
}

void UQuestJournalWidget::OnMarkButtonPressed() {
	UQuest* BindedQuest = QuestDescription->GetBindedQuest();
	if(!BindedQuest)
		return;

	if(OnQuestFocusChange.IsBound())
		OnQuestFocusChange.Broadcast(BindedQuest);
}

void UQuestJournalWidget::OnQuestTaken(UQuest* Quest) {
	if(!QuestJournalElementWidgetClass || !Quest)
		return;

	UQuestJournalElementWidget* QuestJournalElementWidget = CreateWidget<UQuestJournalElementWidget>(this, QuestJournalElementWidgetClass);
	QuestJournalElementWidget->Init(Quest);
	QuestJournalElementWidget->OnQuestClicked.AddUObject(this, &UQuestJournalWidget::ChangeQuestFocus);
	
	QuestJournalElementWidgets.Add(QuestJournalElementWidget);

	ChangeQuestFocus(Quest);
	RefreshChildrens();
}

void UQuestJournalWidget::OnQuestDiscarded(UQuest* Quest) {
	auto Predicate = [&](const UQuestJournalElementWidget* QuestJournalElementWidget) -> bool {
		return QuestJournalElementWidget->GetBindedQuest() == Quest;
	};
	
	if(!Quest)
		return;
	
	UQuestJournalElementWidget** FindedQuestJournalElementWidget = QuestJournalElementWidgets.FindByPredicate(Predicate);
	QuestJournalElementWidgets.Remove(*FindedQuestJournalElementWidget);

	ChangeQuestFocus(nullptr);
	if(OnQuestFocusChange.IsBound())
		OnQuestFocusChange.Broadcast(nullptr);
	
	RefreshChildrens();
}