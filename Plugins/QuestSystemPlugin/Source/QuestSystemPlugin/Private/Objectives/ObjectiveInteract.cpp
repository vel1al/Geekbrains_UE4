#include "Objectives/ObjectiveInteract.h"

#include "Core/QuestManager.h"


void UObjectiveInteract::Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) {
	if(!TargetActorInteractedWith)
		return;

	if(QuestManagerToBind)
		QuestManagerToBind->QuestDelegates.OnActorInteract->AddDynamic(this, &UObjectiveInteract::OnInteract);

	BindedPlayer = PlayerToBind;
}

void UObjectiveInteract::OnInteract(const AActor* InteractingActor) {
	if(InteractingActor != TargetActorInteractedWith)
		return;

	CompleteObjective();
}