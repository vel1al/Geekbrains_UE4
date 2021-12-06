#include "Objectives/ObjectiveLocation.h"

#include "LocationMarker.h"


void UObjectiveLocation::Init(UQuestManager* QuestManagerToBind, APawn* PlayerToBind) {
	if(!LocationActor)
		return;

	ILocationMarker* LocationMarker = Cast<ILocationMarker>(LocationActor);
	if(!LocationMarker)
		return;
 
	LocationMarker->OnLocationEnter.AddUObject(this, &UObjectiveLocation::OnOverlap);
 
	BindedPlayer = PlayerToBind;
}

void UObjectiveLocation::OnOverlap(AActor* OverlappingActor, AActor* SelfActor) {
	if(!OverlappingActor)
		return;
	if(!SelfActor)
		return;
	
	if(OverlappingActor != BindedPlayer || SelfActor != LocationActor)
		return;

	CompleteObjective();
}