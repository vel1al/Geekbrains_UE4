#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Quest.h"

#include "QuestManager.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyKill, const AActor*, KilledActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorInteract, const AActor*, InteractingActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCollect, FName, CollectedItem);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreReceive, int32, ScoreValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoneyReceive, int32, MoneyValue);

DECLARE_EVENT_OneParam(UQuestManager, FOnQuestTake, UQuest*);
DECLARE_EVENT_OneParam(UQuestManager, FOnQuestDiscrad, UQuest*);

class UQuestJournalWidget;
class UQuestTakeDialog;
class UQuestHUD;


USTRUCT()
struct FQuestDelegates {
		GENERATED_BODY()
	
	public:
		FOnEnemyKill* OnEnemyKill; 
		FOnActorInteract* OnActorInteract;
		FOnItemCollect* OnItemCollect;
		FOnMoneyReceive* OnMoneyReceive;
		FOnScoreReceive* OnScoreReceive; 
};

USTRUCT()
struct FQuestManagerInitializer {
		GENERATED_BODY()

	public:
		APawn* PlayerToBind;
		UUserWidget* QuestJournalWidgetToBind;
		UUserWidget* QuestHUDToBind;
		TSubclassOf<UQuestTakeDialog> QuestTakeDialogClassToBind;
		
		FQuestDelegates QuestDelegatesToBind;
};

UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestManager : public UGameInstanceSubsystem{
	GENERATED_BODY()

	public:
		UFUNCTION()
		void TakeQuest(UQuest* Quest);
		UFUNCTION()
		void DiscardQuest(UQuest* Quest);
	
		void SetActiveQuest(UQuest* QuestToActive, const bool bState);
		void SetActiveQuest(const int32 LocalIndex, const bool bState);

		void Init(const FQuestManagerInitializer& QuestManagerInitializer);

		void CallQuestTakeDialog(UQuest* Quest);
	
		TArray<UQuest*> GetTakenQuests() const;
	
		FQuestDelegates QuestDelegates;

		FOnQuestTake OnQuestTaken;
		FOnQuestDiscrad OnQuestDiscard;
	
	protected:
		UFUNCTION()
		void OnQuestFocusChanged(UQuest* Quest);
	
		APawn* BindedPlayer;
		UQuestJournalWidget* BindedQuestJournalWidget;
		UQuestHUD* BindedQuestHUD;

		TSubclassOf<UQuestTakeDialog> QuestTakeDialogClass;
	
		UPROPERTY()
		TArray<UQuest*> TakenQuestsList;
};