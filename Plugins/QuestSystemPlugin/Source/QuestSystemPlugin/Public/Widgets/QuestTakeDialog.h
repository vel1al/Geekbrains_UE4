#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestTakeDialog.generated.h"

class UQuest;
class UButton;
class UQuestManager;
class UQuestDescriptionWidget;

DECLARE_EVENT_OneParam(UQuestTakeDialog, FOnApply, UQuest*);


UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestTakeDialog : public UUserWidget{
		GENERATED_BODY()

	public:
		void Init(UQuest* QuestToBind);
		UQuest* GetBindedQuest() const;
	
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UQuestDescriptionWidget* QuestDescription;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UButton* AcceptButton;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UButton* DiscardButton;

		FOnApply OnApply;
	
	protected:
		virtual void NativeConstruct() override;
	
		UFUNCTION()
		void OnAcceptButtonPressed();
		UFUNCTION()
		void OnDiscardButtonPressed();

	
		UQuest* BindedQuest;
};
