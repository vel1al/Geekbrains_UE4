#include "Editor/DetailCustomizations/Public/DetailCustomizations.h"
#include "Editor/PropertyEditor/Public/IDetailCustomization.h"
#include "Editor/PropertyEditor/Public/DetailCategoryBuilder.h"
#include "Editor/PropertyEditor/Public/DetailLayoutBuilder.h"

#include "Quest.h"


#pragma once

class FObjectiveClassDetails : public IDetailCustomization{
	public:
		static TSharedRef<IDetailCustomization> MakeInstance();

		static void RegisterChanges();
		virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};