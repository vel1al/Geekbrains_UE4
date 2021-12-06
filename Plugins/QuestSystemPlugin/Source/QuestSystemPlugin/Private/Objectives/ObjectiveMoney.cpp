#include "Objectives/ObjectiveMoney.h"

#include "Core/QuestManager.h"


void UObjectiveMoney::Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) {
	BindedPlayer = PlayerToBind;
	MoneyCount = 0;
	
	if(QuestManagerToBind)
		QuestManagerToBind->QuestDelegates.OnMoneyReceive->AddDynamic(this, &UObjectiveMoney::OnMoneyReceive);
}

void UObjectiveMoney::OnMoneyReceive(const int32 MoneyValue) {
	MoneyCount += MoneyValue;

	if(MoneyCount >= TargetMoneyCount)
		CompleteObjective();
}