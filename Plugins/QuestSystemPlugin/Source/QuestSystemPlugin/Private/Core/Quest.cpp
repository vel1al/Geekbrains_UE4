#include "QuestSystemPlugin/Public/Core/Quest.h"

#include "Objectives/Objective.h"
#include "Objectives/ObjectiveLocation.h"
#include "Objectives/ObjectiveMoney.h"
#include "Objectives/ObjectiveCollect.h"
#include "Objectives/ObjectiveScore.h"
#include "Objectives/ObjectiveInteract.h"
#include "Objectives/ObjectiveKill.h"


void UQuest::Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) {
	BindedPlayer = PlayerToBind;

	if(!QuestManagerToBind)
		return;
	
	for(auto Objective : QuestObjectives)
		if(Objective) {
			Objective->Init(QuestManagerToBind, BindedPlayer);
			Objective->OnObjectiveCompleted.AddUObject(this, &UQuest::OnObjectiveCompleted);

			if(!bKeepObjectivesOrder)
				Objective->ToggleObjective(true);
		}
}

void UQuest::ToggleQuestState(const bool bState) {
	if(bIsStoryQuest)
		if(PreviousQuest)
			if(!PreviousQuest->GetQuestState())
				return; 
				
	bIsTaken = bState;
}

bool UQuest::GetQuestState() const {
	return bIsTaken;
}

bool UQuest::GetQuestComplete() const {
	return bIsCompleted;
}

TArray<UObjective*> UQuest::GetObjectives() const {
	return QuestObjectives;
}

void UQuest::OnObjectiveCompleted(const UObjective* CompletedObjective) {
	for(const auto Objective : QuestObjectives) {
		if(!Objective->GetObjectiveIsComplete()) {
			if(bKeepObjectivesOrder)
				Objective->ToggleObjective(true);
			else if(Objective == CompletedObjective)
					Objective->ToggleObjective(false);
			
			return;
		}
	}
	
	bIsCompleted = true;

	if(OnQuestCompleted.IsBound())
		OnQuestCompleted.Broadcast(this);
}

#if WITH_EDITOR
	FReply UQuest::CreateObjectivesInstances() {
		switch(ObjectiveTypeToCreate) {
			case EObjectiveType::Collect: CreateObjectiveCollect(); break;
			case EObjectiveType::Score: CreateObjectiveScore(); break;
			case EObjectiveType::Money: CreateObjectiveMoney(); break;
			case EObjectiveType::Kill: CreateObjectiveKill(); break;
			case EObjectiveType::Interact: CreateObjectiveInteract(); break;
			case EObjectiveType::Location: CreateObjectiveLocation(); break;
		}

		return FReply::Handled();
	}

	void UQuest::CreateObjectiveCollect() {
		//QuestObjectives.Add(NewObject<UObjectiveCollect>(this));
	}

	void UQuest::CreateObjectiveKill() {
		QuestObjectives.Add(NewObject<UObjectiveKill>(this));
	}

	void UQuest::CreateObjectiveScore() {
		QuestObjectives.Add(NewObject<UObjectiveScore>(this));
	}

	void UQuest::CreateObjectiveMoney() {
		QuestObjectives.Add(NewObject<UObjectiveMoney>(this));
	}

	void UQuest::CreateObjectiveInteract() {
		QuestObjectives.Add(NewObject<UObjectiveInteract>(this));
	}

	void UQuest::CreateObjectiveLocation() {
		QuestObjectives.Add(NewObject<UObjectiveLocation>(this));
	}
#endif