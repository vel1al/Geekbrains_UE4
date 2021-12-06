#include "Objectives/Objective.h"

void UObjective::ToggleObjective(const bool bState) {
	bIsActive = bState;
}

bool UObjective::GetObjectiveState() const {
	return bIsActive;
}

bool UObjective::GetObjectiveIsComplete() const {
	return bIsCompleted;
}

FText UObjective::GetDescription() const {
	return Description;
}

int32 UObjective::GetReward() const {
	return RewardForComplete;
}

void UObjective::Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) {
	return;
}

void UObjective::CompleteObjective() {
	bIsCompleted = true;
	
	if(OnObjectiveCompleted.IsBound())
		OnObjectiveCompleted.Broadcast(this);
}
