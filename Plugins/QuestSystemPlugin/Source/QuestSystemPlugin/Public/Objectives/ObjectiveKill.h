#pragma once

#include "CoreMinimal.h"
#include "Objectives/Objective.h"
#include "Engine/TriggerBox.h"

#include "ObjectiveKill.generated.h"

class ATriggerBox;


UCLASS()
class QUESTSYSTEMPLUGIN_API UObjectiveKill: public UObjective {
		GENERATED_BODY()
	public:
		virtual void Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) override;

		UFUNCTION()
		void OnKill(const AActor* KilledActor);
		
	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* TargetToKill = nullptr;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool bIsCountKills;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (EditCondition = "bIsCountKills"))
		int32 TargetKillsCount = 0;

		int32 KillsCount;
	
		APawn* BindedPlayer;
};