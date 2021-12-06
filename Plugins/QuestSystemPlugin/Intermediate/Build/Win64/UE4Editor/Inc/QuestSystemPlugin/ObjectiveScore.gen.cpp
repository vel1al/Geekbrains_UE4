// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Objectives/ObjectiveScore.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveScore() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveScore_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveScore();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UObjectiveScore::execOnScoreReceive)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_ScoreValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnScoreReceive(Z_Param_ScoreValue);
		P_NATIVE_END;
	}
	void UObjectiveScore::StaticRegisterNativesUObjectiveScore()
	{
		UClass* Class = UObjectiveScore::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnScoreReceive", &UObjectiveScore::execOnScoreReceive },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics
	{
		struct ObjectiveScore_eventOnScoreReceive_Parms
		{
			int32 ScoreValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ScoreValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::NewProp_ScoreValue = { "ScoreValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectiveScore_eventOnScoreReceive_Parms, ScoreValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::NewProp_ScoreValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveScore.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectiveScore, nullptr, "OnScoreReceive", nullptr, nullptr, sizeof(ObjectiveScore_eventOnScoreReceive_Parms), Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectiveScore_OnScoreReceive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectiveScore_OnScoreReceive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UObjectiveScore_NoRegister()
	{
		return UObjectiveScore::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveScore_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetScoreCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetScoreCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveScore_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObjective,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UObjectiveScore_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UObjectiveScore_OnScoreReceive, "OnScoreReceive" }, // 2206196762
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveScore_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objectives/ObjectiveScore.h" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveScore.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveScore_Statics::NewProp_TargetScoreCount_MetaData[] = {
		{ "Category", "ObjectiveScore" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveScore.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UObjectiveScore_Statics::NewProp_TargetScoreCount = { "TargetScoreCount", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveScore, TargetScoreCount), METADATA_PARAMS(Z_Construct_UClass_UObjectiveScore_Statics::NewProp_TargetScoreCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveScore_Statics::NewProp_TargetScoreCount_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectiveScore_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveScore_Statics::NewProp_TargetScoreCount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveScore_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveScore>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveScore_Statics::ClassParams = {
		&UObjectiveScore::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UObjectiveScore_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveScore_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveScore_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveScore_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveScore()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveScore_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveScore, 444043937);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjectiveScore>()
	{
		return UObjectiveScore::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveScore(Z_Construct_UClass_UObjectiveScore, &UObjectiveScore::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjectiveScore"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveScore);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
