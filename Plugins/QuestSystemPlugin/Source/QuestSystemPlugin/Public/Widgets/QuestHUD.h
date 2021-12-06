#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestHUD.generated.h"

class UQuest;
class URichTextBlock;
class UVerticalBox;
class UObjectiveDescriptionWidget;


UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestHUD : public UUserWidget{
		GENERATED_BODY()
	
	public:
		void Init(UQuest* QuestToBind);
		UQuest* GetBindedQuest() const;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		URichTextBlock* QuestName;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UVerticalBox* ObjectivesVerticalBox;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<UObjectiveDescriptionWidget> ObjectiveDescriptionWidgetClass;
	
	protected:
		UQuest* BindedQuest;
};