#pragma once

#include "CoreMinimal.h"
#include "Objectives/Objective.h"

#include "ObjectiveScore.generated.h"

class ATriggerBox;


UCLASS()
class QUESTSYSTEMPLUGIN_API UObjectiveScore: public UObjective {
	GENERATED_BODY()
public:
	virtual void Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) override;

	UFUNCTION()
	void OnScoreReceive(int32 ScoreValue);
		
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 TargetScoreCount;

	int32 ScoreCount;
	
	APawn* BindedPlayer;
};