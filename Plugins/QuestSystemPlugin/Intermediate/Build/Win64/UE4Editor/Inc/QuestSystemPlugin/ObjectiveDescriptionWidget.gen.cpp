// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Widgets/ObjectiveDescriptionWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveDescriptionWidget() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveDescriptionWidget_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveDescriptionWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	UMG_API UClass* Z_Construct_UClass_URichTextBlock_NoRegister();
// End Cross Module References
	void UObjectiveDescriptionWidget::StaticRegisterNativesUObjectiveDescriptionWidget()
	{
	}
	UClass* Z_Construct_UClass_UObjectiveDescriptionWidget_NoRegister()
	{
		return UObjectiveDescriptionWidget::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveDescriptionWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectiveDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ObjectiveDescription;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Widgets/ObjectiveDescriptionWidget.h" },
		{ "ModuleRelativePath", "Public/Widgets/ObjectiveDescriptionWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::NewProp_ObjectiveDescription_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ObjectiveDescriptionWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/ObjectiveDescriptionWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::NewProp_ObjectiveDescription = { "ObjectiveDescription", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveDescriptionWidget, ObjectiveDescription), Z_Construct_UClass_URichTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::NewProp_ObjectiveDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::NewProp_ObjectiveDescription_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::NewProp_ObjectiveDescription,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveDescriptionWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::ClassParams = {
		&UObjectiveDescriptionWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveDescriptionWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveDescriptionWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveDescriptionWidget, 1265556987);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjectiveDescriptionWidget>()
	{
		return UObjectiveDescriptionWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveDescriptionWidget(Z_Construct_UClass_UObjectiveDescriptionWidget, &UObjectiveDescriptionWidget::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjectiveDescriptionWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveDescriptionWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
