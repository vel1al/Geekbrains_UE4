#include "Objectives/ObjectiveScore.h"

#include "Core/QuestManager.h"


void UObjectiveScore::Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) {
	BindedPlayer = PlayerToBind;
	ScoreCount = 0;
	
	if(QuestManagerToBind)
		QuestManagerToBind->QuestDelegates.OnScoreReceive->AddDynamic(this, &UObjectiveScore::OnScoreReceive);
}

void UObjectiveScore::OnScoreReceive(int32 ScoreValue) {
	ScoreCount += ScoreValue;

	if(ScoreCount >= TargetScoreCount)
		CompleteObjective();
}