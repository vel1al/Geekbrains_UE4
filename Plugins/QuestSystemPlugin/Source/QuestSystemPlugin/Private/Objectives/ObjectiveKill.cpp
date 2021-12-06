#include "Objectives/ObjectiveKill.h"

#include "Core/QuestManager.h"


void UObjectiveKill::Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) {
	BindedPlayer = PlayerToBind;
	KillsCount = 0;
	
	if(QuestManagerToBind)
		QuestManagerToBind->QuestDelegates.OnEnemyKill->AddDynamic(this, &UObjectiveKill::OnKill);
}

void UObjectiveKill::OnKill(const AActor* KilledActor) {
	if(TargetToKill)
		if(KilledActor != TargetToKill)
			return;

	if(bIsCountKills) {
		KillsCount++;
		
		if(KillsCount >= TargetKillsCount)
			CompleteObjective();
	}
	else
		CompleteObjective();
}
