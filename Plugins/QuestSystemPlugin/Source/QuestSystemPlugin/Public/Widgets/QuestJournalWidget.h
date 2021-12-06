#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestJournalWidget.generated.h"


class UQuest;
class UButton;
class UQuestHUD;
class UVerticalBox;
class UQuestManager;
class UQuestTakeDialog;
class UQuestDescriptionWidget;
class UQuestJournalElementWidget;

DECLARE_EVENT_OneParam(UQuestJournalWidget, FOnQuestFocusChange, UQuest*)


UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestJournalWidget : public UUserWidget {
		GENERATED_BODY()

	public:
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UQuestDescriptionWidget* QuestDescription;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UVerticalBox* ActiveQuestVerticalBox;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UButton* DiscardButton;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UButton* MarkButton;
	
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<UQuestJournalElementWidget> QuestJournalElementWidgetClass;

		FOnQuestFocusChange OnQuestFocusChange;
	
	protected:
		virtual void NativeConstruct() override;
		void RefreshChildrens();

		void ChangeQuestFocus(UQuest* Quest);
	
		UFUNCTION()
		void OnDiscardButtonPressed();
		UFUNCTION()
		void OnMarkButtonPressed();
	
		UFUNCTION()
		void OnQuestTaken(UQuest* Quest);
		UFUNCTION()
		void OnQuestDiscarded(UQuest* Quest);

		UPROPERTY()
		TArray<UQuestJournalElementWidget*> QuestJournalElementWidgets;
	
		UQuestManager* BindedQuestManager;
};