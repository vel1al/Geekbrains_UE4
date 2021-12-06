#pragma once

#include "CoreMinimal.h"
#include "Objectives/Objective.h"
#include "Engine/TriggerBox.h"

#include "ObjectiveLocation.generated.h"

class ATriggerBox;


UCLASS()
class QUESTSYSTEMPLUGIN_API UObjectiveLocation : public UObjective {
		GENERATED_BODY()
	public:
		virtual void Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) override;

		UFUNCTION()
		void OnOverlap(AActor* OverlappingActor, AActor* SelfActor);
	
	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* LocationActor;

		APawn* BindedPlayer;
};
