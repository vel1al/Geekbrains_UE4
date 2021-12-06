#pragma once

#include "UnrealEd.h"
#include "Engine/DataAsset.h"
#include "ObjectiveObjectFactory.generated.h"


UCLASS()
class QUESTSYSTEMPLUGIN_API UObjectiveObjectFactory : public UFactory{
		GENERATED_UCLASS_BODY()
	
		virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
		virtual bool CanCreateNew() const override;
};