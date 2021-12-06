#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestJournalElementWidget.generated.h"

class UQuest;
class UImage;
class UButton;
class URichTextBlock;

DECLARE_EVENT_OneParam(UQuestJournalElementWidget, FOnQuestClicked, UQuest*)

UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestJournalElementWidget : public UUserWidget{
		GENERATED_BODY()

	public:
		void Init(UQuest* QuestToBind);
		void SetActive(bool bState);

		bool GetActive() const;
		UQuest* GetBindedQuest() const;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UButton* WidgetButton;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UImage* OnMarkedImage;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		URichTextBlock* QuestName;

		FOnQuestClicked OnQuestClicked;
	
	protected:
		virtual void NativeConstruct() override;
		UFUNCTION()
		void OnClickedBridge();
	
		UQuest* BindedQuest;

		bool bActive;
};