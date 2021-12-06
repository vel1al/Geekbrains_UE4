// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Widgets/QuestJournalElementWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestJournalElementWidget() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestJournalElementWidget_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestJournalElementWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_URichTextBlock_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UQuestJournalElementWidget::execOnClickedBridge)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnClickedBridge();
		P_NATIVE_END;
	}
	void UQuestJournalElementWidget::StaticRegisterNativesUQuestJournalElementWidget()
	{
		UClass* Class = UQuestJournalElementWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnClickedBridge", &UQuestJournalElementWidget::execOnClickedBridge },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalElementWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestJournalElementWidget, nullptr, "OnClickedBridge", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuestJournalElementWidget_NoRegister()
	{
		return UQuestJournalElementWidget::StaticClass();
	}
	struct Z_Construct_UClass_UQuestJournalElementWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WidgetButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WidgetButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnMarkedImage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OnMarkedImage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestName_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestJournalElementWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestJournalElementWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestJournalElementWidget_OnClickedBridge, "OnClickedBridge" }, // 1655667394
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalElementWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Widgets/QuestJournalElementWidget.h" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalElementWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_WidgetButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestJournalElementWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalElementWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_WidgetButton = { "WidgetButton", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalElementWidget, WidgetButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_WidgetButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_WidgetButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_OnMarkedImage_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestJournalElementWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalElementWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_OnMarkedImage = { "OnMarkedImage", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalElementWidget, OnMarkedImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_OnMarkedImage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_OnMarkedImage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_QuestName_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestJournalElementWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalElementWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_QuestName = { "QuestName", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalElementWidget, QuestName), Z_Construct_UClass_URichTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_QuestName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_QuestName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestJournalElementWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_WidgetButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_OnMarkedImage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalElementWidget_Statics::NewProp_QuestName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestJournalElementWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestJournalElementWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestJournalElementWidget_Statics::ClassParams = {
		&UQuestJournalElementWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestJournalElementWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalElementWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestJournalElementWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalElementWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestJournalElementWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestJournalElementWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestJournalElementWidget, 1118512763);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UQuestJournalElementWidget>()
	{
		return UQuestJournalElementWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestJournalElementWidget(Z_Construct_UClass_UQuestJournalElementWidget, &UQuestJournalElementWidget::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UQuestJournalElementWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestJournalElementWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
