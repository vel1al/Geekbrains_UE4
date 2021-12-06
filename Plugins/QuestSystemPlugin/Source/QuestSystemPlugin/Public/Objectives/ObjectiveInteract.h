#pragma once

#include "CoreMinimal.h"
#include "Objectives/Objective.h"

#include "ObjectiveInteract.generated.h"


UCLASS()
class QUESTSYSTEMPLUGIN_API UObjectiveInteract : public UObjective {
		GENERATED_BODY()
	public:
		virtual void Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) override;

		UFUNCTION()
		void OnInteract(const AActor* InteractingActor);

		UPROPERTY(EditAnywhere)
		AActor* TargetActorInteractedWith;
		
	protected:
		APawn* BindedPlayer;
};