// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Widgets/QuestJournalWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestJournalWidget() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestJournalWidget_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestJournalWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuest_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestDescriptionWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestJournalElementWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UQuestJournalWidget::execOnQuestDiscarded)
	{
		P_GET_OBJECT(UQuest,Z_Param_Quest);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnQuestDiscarded(Z_Param_Quest);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestJournalWidget::execOnQuestTaken)
	{
		P_GET_OBJECT(UQuest,Z_Param_Quest);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnQuestTaken(Z_Param_Quest);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestJournalWidget::execOnMarkButtonPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMarkButtonPressed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestJournalWidget::execOnDiscardButtonPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDiscardButtonPressed();
		P_NATIVE_END;
	}
	void UQuestJournalWidget::StaticRegisterNativesUQuestJournalWidget()
	{
		UClass* Class = UQuestJournalWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnDiscardButtonPressed", &UQuestJournalWidget::execOnDiscardButtonPressed },
			{ "OnMarkButtonPressed", &UQuestJournalWidget::execOnMarkButtonPressed },
			{ "OnQuestDiscarded", &UQuestJournalWidget::execOnQuestDiscarded },
			{ "OnQuestTaken", &UQuestJournalWidget::execOnQuestTaken },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestJournalWidget, nullptr, "OnDiscardButtonPressed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestJournalWidget, nullptr, "OnMarkButtonPressed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics
	{
		struct QuestJournalWidget_eventOnQuestDiscarded_Parms
		{
			UQuest* Quest;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Quest;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::NewProp_Quest = { "Quest", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(QuestJournalWidget_eventOnQuestDiscarded_Parms, Quest), Z_Construct_UClass_UQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::NewProp_Quest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestJournalWidget, nullptr, "OnQuestDiscarded", nullptr, nullptr, sizeof(QuestJournalWidget_eventOnQuestDiscarded_Parms), Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics
	{
		struct QuestJournalWidget_eventOnQuestTaken_Parms
		{
			UQuest* Quest;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Quest;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::NewProp_Quest = { "Quest", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(QuestJournalWidget_eventOnQuestTaken_Parms, Quest), Z_Construct_UClass_UQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::NewProp_Quest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestJournalWidget, nullptr, "OnQuestTaken", nullptr, nullptr, sizeof(QuestJournalWidget_eventOnQuestTaken_Parms), Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuestJournalWidget_NoRegister()
	{
		return UQuestJournalWidget::StaticClass();
	}
	struct Z_Construct_UClass_UQuestJournalWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestDescription;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveQuestVerticalBox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActiveQuestVerticalBox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DiscardButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DiscardButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MarkButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MarkButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestJournalElementWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_QuestJournalElementWidgetClass;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestJournalElementWidgets_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestJournalElementWidgets_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_QuestJournalElementWidgets;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestJournalWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestJournalWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestJournalWidget_OnDiscardButtonPressed, "OnDiscardButtonPressed" }, // 1889229345
		{ &Z_Construct_UFunction_UQuestJournalWidget_OnMarkButtonPressed, "OnMarkButtonPressed" }, // 10566563
		{ &Z_Construct_UFunction_UQuestJournalWidget_OnQuestDiscarded, "OnQuestDiscarded" }, // 1674436859
		{ &Z_Construct_UFunction_UQuestJournalWidget_OnQuestTaken, "OnQuestTaken" }, // 2091165605
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Widgets/QuestJournalWidget.h" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestDescription_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestJournalWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestDescription = { "QuestDescription", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalWidget, QuestDescription), Z_Construct_UClass_UQuestDescriptionWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestDescription_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_ActiveQuestVerticalBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestJournalWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_ActiveQuestVerticalBox = { "ActiveQuestVerticalBox", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalWidget, ActiveQuestVerticalBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_ActiveQuestVerticalBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_ActiveQuestVerticalBox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_DiscardButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestJournalWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_DiscardButton = { "DiscardButton", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalWidget, DiscardButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_DiscardButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_DiscardButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_MarkButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestJournalWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_MarkButton = { "MarkButton", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalWidget, MarkButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_MarkButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_MarkButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgetClass_MetaData[] = {
		{ "Category", "QuestJournalWidget" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgetClass = { "QuestJournalElementWidgetClass", nullptr, (EPropertyFlags)0x0014000000010005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalWidget, QuestJournalElementWidgetClass), Z_Construct_UClass_UQuestJournalElementWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgets_Inner = { "QuestJournalElementWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UQuestJournalElementWidget_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestJournalWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgets = { "QuestJournalElementWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestJournalWidget, QuestJournalElementWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgets_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestJournalWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestDescription,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_ActiveQuestVerticalBox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_DiscardButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_MarkButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgets_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestJournalWidget_Statics::NewProp_QuestJournalElementWidgets,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestJournalWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestJournalWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestJournalWidget_Statics::ClassParams = {
		&UQuestJournalWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestJournalWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestJournalWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestJournalWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestJournalWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestJournalWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestJournalWidget, 2438501294);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UQuestJournalWidget>()
	{
		return UQuestJournalWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestJournalWidget(Z_Construct_UClass_UQuestJournalWidget, &UQuestJournalWidget::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UQuestJournalWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestJournalWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
