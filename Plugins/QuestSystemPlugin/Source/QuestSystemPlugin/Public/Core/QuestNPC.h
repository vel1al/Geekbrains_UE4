#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "QuestManager.h"
#include "QuestNPC.generated.h"


UINTERFACE(MinimalAPI)
class UQuestNPC : public UInterface{
	GENERATED_BODY()
};

class UQuest;


class QUESTSYSTEMPLUGIN_API IQuestNPC{
	GENERATED_BODY()

	public:
		virtual void GiveQuest() = 0;

		UFUNCTION(BlueprintNativeEvent)
		bool GiveQuestCondition();
		virtual bool GiveQuestCondition_Implementation() = 0;
};
