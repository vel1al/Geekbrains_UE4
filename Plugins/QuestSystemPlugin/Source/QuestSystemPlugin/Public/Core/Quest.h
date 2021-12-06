#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/SlateCore/Public/Input/Reply.h"

#include "Quest.generated.h"


DECLARE_EVENT_OneParam(UQuest, FOnQuestCompleted, const class UQuest*)

class UQuestManager;
class UObjective;

UENUM()
enum class EObjectiveType : uint8 {
	Collect = 0 UMETA(DisplayName = "Collect Item"),
	Score = 1 UMETA(DisplayName = "Receive Score"),
	Money = 2 UMETA(DisplayName = "Receive Money"),
	Kill = 3 UMETA(DisplayName = "Kill enemys"),
	Interact = 4 UMETA(DisplayName = "Interact with"),
	Location = 5 UMETA(DisplayName = "Navigate to")
};


UCLASS(Category = "QuestPlugin|Assets", Blueprintable)
class QUESTSYSTEMPLUGIN_API UQuest : public UObject{
		GENERATED_BODY()

	public:
		#if WITH_EDITOR
			UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
			EObjectiveType ObjectiveTypeToCreate;
						
			
			FReply CreateObjectivesInstances();

			void CreateObjectiveCollect();
			void CreateObjectiveKill();
			void CreateObjectiveScore();
			void CreateObjectiveMoney();
			void CreateObjectiveInteract();
			void CreateObjectiveLocation();
		#endif
	
		UQuest() = default;
	
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FText Name;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FText Description;
	
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool bIsStoryQuest = true;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (EditCondition = "bIsStoreQuest"))
		class UQuest* PreviousQuest;
		
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool bKeepObjectivesOrder = true;

		FOnQuestCompleted OnQuestCompleted;
	
		void Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind);
	
		void ToggleQuestState(const bool bState);
		bool GetQuestState() const;

		bool GetQuestComplete() const;
	
		TArray<UObjective*> GetObjectives() const;

	protected:
		bool bIsTaken;
		bool bIsCompleted;

		APawn* BindedPlayer;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
		TArray<UObjective*> QuestObjectives;
		
		UFUNCTION()
		void OnObjectiveCompleted(const UObjective* CompletedObjective);
};