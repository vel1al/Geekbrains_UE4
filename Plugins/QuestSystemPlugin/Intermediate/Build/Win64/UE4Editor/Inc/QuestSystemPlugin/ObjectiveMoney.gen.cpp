// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Objectives/ObjectiveMoney.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveMoney() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveMoney_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveMoney();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UObjectiveMoney::execOnMoneyReceive)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_MoneyValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMoneyReceive(Z_Param_MoneyValue);
		P_NATIVE_END;
	}
	void UObjectiveMoney::StaticRegisterNativesUObjectiveMoney()
	{
		UClass* Class = UObjectiveMoney::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnMoneyReceive", &UObjectiveMoney::execOnMoneyReceive },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics
	{
		struct ObjectiveMoney_eventOnMoneyReceive_Parms
		{
			int32 MoneyValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoneyValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MoneyValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::NewProp_MoneyValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::NewProp_MoneyValue = { "MoneyValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectiveMoney_eventOnMoneyReceive_Parms, MoneyValue), METADATA_PARAMS(Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::NewProp_MoneyValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::NewProp_MoneyValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::NewProp_MoneyValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveMoney.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectiveMoney, nullptr, "OnMoneyReceive", nullptr, nullptr, sizeof(ObjectiveMoney_eventOnMoneyReceive_Parms), Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UObjectiveMoney_NoRegister()
	{
		return UObjectiveMoney::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveMoney_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetMoneyCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetMoneyCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveMoney_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObjective,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UObjectiveMoney_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UObjectiveMoney_OnMoneyReceive, "OnMoneyReceive" }, // 711338999
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveMoney_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objectives/ObjectiveMoney.h" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveMoney.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveMoney_Statics::NewProp_TargetMoneyCount_MetaData[] = {
		{ "Category", "ObjectiveMoney" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveMoney.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UObjectiveMoney_Statics::NewProp_TargetMoneyCount = { "TargetMoneyCount", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveMoney, TargetMoneyCount), METADATA_PARAMS(Z_Construct_UClass_UObjectiveMoney_Statics::NewProp_TargetMoneyCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveMoney_Statics::NewProp_TargetMoneyCount_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectiveMoney_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveMoney_Statics::NewProp_TargetMoneyCount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveMoney_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveMoney>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveMoney_Statics::ClassParams = {
		&UObjectiveMoney::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UObjectiveMoney_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveMoney_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveMoney_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveMoney_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveMoney()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveMoney_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveMoney, 1190504371);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjectiveMoney>()
	{
		return UObjectiveMoney::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveMoney(Z_Construct_UClass_UObjectiveMoney, &UObjectiveMoney::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjectiveMoney"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveMoney);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
