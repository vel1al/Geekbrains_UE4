#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveDescriptionWidget.generated.h"

class UObjective;
class URichTextBlock;


UCLASS()
class QUESTSYSTEMPLUGIN_API UObjectiveDescriptionWidget : public UUserWidget{
	GENERATED_BODY()
public:
	void Init(UObjective* ObjectiveToBind);
	UObjective* GetBindedObjective() const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	URichTextBlock* ObjectiveDescription;
	
protected:
	UObjective* BindedObjective;
};
