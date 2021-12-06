#include "Core/ObjectiveObjectFactory.h"
#include "Core/Quest.h"


UObjectiveObjectFactory::UObjectiveObjectFactory(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UQuest::StaticClass();
}

UObject* UObjectiveObjectFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn){
	UQuest* NewObjectAsset = NewObject<UQuest>(InParent,Class, Name, Flags | RF_Transactional);
	
	return NewObjectAsset;
}

bool UObjectiveObjectFactory::CanCreateNew() const{
	return bCreateNew;
}
