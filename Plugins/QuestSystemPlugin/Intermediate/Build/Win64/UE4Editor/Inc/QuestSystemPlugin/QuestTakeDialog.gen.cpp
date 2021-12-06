// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Widgets/QuestTakeDialog.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestTakeDialog() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestTakeDialog_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestTakeDialog();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestDescriptionWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UQuestTakeDialog::execOnDiscardButtonPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDiscardButtonPressed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestTakeDialog::execOnAcceptButtonPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnAcceptButtonPressed();
		P_NATIVE_END;
	}
	void UQuestTakeDialog::StaticRegisterNativesUQuestTakeDialog()
	{
		UClass* Class = UQuestTakeDialog::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnAcceptButtonPressed", &UQuestTakeDialog::execOnAcceptButtonPressed },
			{ "OnDiscardButtonPressed", &UQuestTakeDialog::execOnDiscardButtonPressed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/QuestTakeDialog.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestTakeDialog, nullptr, "OnAcceptButtonPressed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widgets/QuestTakeDialog.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestTakeDialog, nullptr, "OnDiscardButtonPressed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuestTakeDialog_NoRegister()
	{
		return UQuestTakeDialog::StaticClass();
	}
	struct Z_Construct_UClass_UQuestTakeDialog_Statics
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AcceptButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AcceptButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DiscardButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DiscardButton;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestTakeDialog_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestTakeDialog_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestTakeDialog_OnAcceptButtonPressed, "OnAcceptButtonPressed" }, // 312081915
		{ &Z_Construct_UFunction_UQuestTakeDialog_OnDiscardButtonPressed, "OnDiscardButtonPressed" }, // 1833344204
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestTakeDialog_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Widgets/QuestTakeDialog.h" },
		{ "ModuleRelativePath", "Public/Widgets/QuestTakeDialog.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_QuestDescription_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestTakeDialog" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestTakeDialog.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_QuestDescription = { "QuestDescription", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestTakeDialog, QuestDescription), Z_Construct_UClass_UQuestDescriptionWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_QuestDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_QuestDescription_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_AcceptButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestTakeDialog" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestTakeDialog.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_AcceptButton = { "AcceptButton", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestTakeDialog, AcceptButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_AcceptButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_AcceptButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_DiscardButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "QuestTakeDialog" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/QuestTakeDialog.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_DiscardButton = { "DiscardButton", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestTakeDialog, DiscardButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_DiscardButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_DiscardButton_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestTakeDialog_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_QuestDescription,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_AcceptButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestTakeDialog_Statics::NewProp_DiscardButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestTakeDialog_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestTakeDialog>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestTakeDialog_Statics::ClassParams = {
		&UQuestTakeDialog::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestTakeDialog_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestTakeDialog_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestTakeDialog_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestTakeDialog_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestTakeDialog()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestTakeDialog_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestTakeDialog, 1520217816);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UQuestTakeDialog>()
	{
		return UQuestTakeDialog::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestTakeDialog(Z_Construct_UClass_UQuestTakeDialog, &UQuestTakeDialog::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UQuestTakeDialog"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestTakeDialog);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
