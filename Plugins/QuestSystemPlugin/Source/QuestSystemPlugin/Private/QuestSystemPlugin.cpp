#include "QuestSystemPlugin.h"

#include "Core/ObjectiveAssetAction.h"
#include "Core/ObjectiveClassDetails.h"

#define LOCTEXT_NAMESPACE "FQuestSystemPluginModule"


void FQuestSystemPluginModule::StartupModule(){
	FObjectiveAssetAction::RegisterChanges();
	FObjectiveClassDetails::RegisterChanges();
}

void FQuestSystemPluginModule::ShutdownModule(){

}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FQuestSystemPluginModule, QuestSystemPlugin)