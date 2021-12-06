#pragma once

#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "Developer/AssetTools/Public/AssetTypeActions_Base.h"


class QUESTSYSTEMPLUGIN_API FObjectiveAssetAction : public FAssetTypeActions_Base {
	public:
		virtual FText GetName() const override;
		virtual FColor GetTypeColor() const override;
		virtual UClass* GetSupportedClass() const override;
		virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return false; }
		virtual uint32 GetCategories() override;
	
		static void RegisterChanges();
	
};