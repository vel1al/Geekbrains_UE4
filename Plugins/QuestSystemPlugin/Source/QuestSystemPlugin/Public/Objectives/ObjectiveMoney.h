#pragma once

#include "CoreMinimal.h"
#include "Objectives/Objective.h"

#include "ObjectiveMoney.generated.h"

class ATriggerBox;


UCLASS()
class QUESTSYSTEMPLUGIN_API UObjectiveMoney: public UObjective {
	GENERATED_BODY()
public:
	virtual void Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) override;

	UFUNCTION()
	void OnMoneyReceive(const int32 MoneyValue);
		
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 TargetMoneyCount;

	int32 MoneyCount;
	
	APawn* BindedPlayer;
};