#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestDescriptionWidget.generated.h"

class UQuest;
class UScrollBox;
class URichTextBlock;
class UObjectiveDescriptionWidget;

UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestDescriptionWidget : public UUserWidget{
		GENERATED_BODY()
	public:
		void Init(UQuest* QuestToBind);
		UQuest* GetBindedQuest() const;
	
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		URichTextBlock* QuestName;
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
		UScrollBox* ObjectivesScrollBox;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<UObjectiveDescriptionWidget> ObjectiveDescriptionWidgetClass;
	
	protected:
		UQuest* BindedQuest;
};
