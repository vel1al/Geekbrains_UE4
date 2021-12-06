#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Objective.generated.h"

DECLARE_EVENT_OneParam(UObjective, FOnObjectiveCompleted, const class UObjective*)

class APlayerVehicle;
class UQuestManager;

UCLASS(Category = "QuestPlugin|Assets", Abstract)
class QUESTSYSTEMPLUGIN_API UObjective : public UObject{
		GENERATED_BODY()

	public:
		FOnObjectiveCompleted OnObjectiveCompleted;
	
		void ToggleObjective(const bool bState);

		bool GetObjectiveState() const;
		bool GetObjectiveIsComplete() const;

		FText GetDescription() const;

		int32 GetReward() const;
	
		virtual void Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind);

	protected:
		void CompleteObjective();
	
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FText Description;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int32 RewardForComplete;
	
		bool bIsCompleted;
		bool bIsActive;
};
