// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Widgets/QuestHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestHUD() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestHUD_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestHUD();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	UMG_API UClass* Z_Construct_UClass_URichTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveDescriptionWidget_NoRegister();
// End Cross Module References
	void UQuestHUD::StaticRegisterNativesUQuestHUD()
	{
	}
	UClass* Z_Construct_UClass_UQuestHUD_NoRegister()
	{
		return UQuestHUD::StaticClass();
	}
	struct Z_Construct_UClass_UQuestHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestName_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectivesVerticalBox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ObjectivesVerticalBox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectiveDescriptionWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ObjectiveDescriptionWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestHUD_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Widgets/QuestHUD.h" },
		{ "ModuleRelativePath", "Public/Widgets/QuestHUD.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestHUD_Statics::NewProp_QuestName_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestHUD" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestHUD_Statics::NewProp_QuestName = { "QuestName", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestHUD, QuestName), Z_Construct_UClass_URichTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestHUD_Statics::NewProp_QuestName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestHUD_Statics::NewProp_QuestName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectivesVerticalBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestHUD" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectivesVerticalBox = { "ObjectivesVerticalBox", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestHUD, ObjectivesVerticalBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectivesVerticalBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectivesVerticalBox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectiveDescriptionWidgetClass_MetaData[] = {
		{ "Category", "QuestHUD" },
		{ "ModuleRelativePath", "Public/Widgets/QuestHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectiveDescriptionWidgetClass = { "ObjectiveDescriptionWidgetClass", nullptr, (EPropertyFlags)0x0014000000010005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestHUD, ObjectiveDescriptionWidgetClass), Z_Construct_UClass_UObjectiveDescriptionWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectiveDescriptionWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectiveDescriptionWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestHUD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestHUD_Statics::NewProp_QuestName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectivesVerticalBox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestHUD_Statics::NewProp_ObjectiveDescriptionWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestHUD_Statics::ClassParams = {
		&UQuestHUD::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UQuestHUD_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestHUD_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestHUD, 563829459);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UQuestHUD>()
	{
		return UQuestHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestHUD(Z_Construct_UClass_UQuestHUD, &UQuestHUD::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UQuestHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
