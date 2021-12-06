// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Core/QuestManager.h"
#include "Engine/Classes/Engine/GameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestManager() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	QUESTSYSTEMPLUGIN_API UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature();
	QUESTSYSTEMPLUGIN_API UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature();
	QUESTSYSTEMPLUGIN_API UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	QUESTSYSTEMPLUGIN_API UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature();
	QUESTSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FQuestManagerInitializer();
	QUESTSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FQuestDelegates();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestManager_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestManager();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuest_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics
	{
		struct _Script_QuestSystemPlugin_eventOnMoneyReceive_Parms
		{
			int32 MoneyValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MoneyValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::NewProp_MoneyValue = { "MoneyValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_QuestSystemPlugin_eventOnMoneyReceive_Parms, MoneyValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::NewProp_MoneyValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_QuestSystemPlugin, nullptr, "OnMoneyReceive__DelegateSignature", nullptr, nullptr, sizeof(_Script_QuestSystemPlugin_eventOnMoneyReceive_Parms), Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_QuestSystemPlugin_OnMoneyReceive__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics
	{
		struct _Script_QuestSystemPlugin_eventOnScoreReceive_Parms
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::NewProp_ScoreValue = { "ScoreValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_QuestSystemPlugin_eventOnScoreReceive_Parms, ScoreValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::NewProp_ScoreValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_QuestSystemPlugin, nullptr, "OnScoreReceive__DelegateSignature", nullptr, nullptr, sizeof(_Script_QuestSystemPlugin_eventOnScoreReceive_Parms), Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_QuestSystemPlugin_OnScoreReceive__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics
	{
		struct _Script_QuestSystemPlugin_eventOnItemCollect_Parms
		{
			FName CollectedItem;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_CollectedItem;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::NewProp_CollectedItem = { "CollectedItem", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_QuestSystemPlugin_eventOnItemCollect_Parms, CollectedItem), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::NewProp_CollectedItem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_QuestSystemPlugin, nullptr, "OnItemCollect__DelegateSignature", nullptr, nullptr, sizeof(_Script_QuestSystemPlugin_eventOnItemCollect_Parms), Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_QuestSystemPlugin_OnItemCollect__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics
	{
		struct _Script_QuestSystemPlugin_eventOnActorInteract_Parms
		{
			const AActor* InteractingActor;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InteractingActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InteractingActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::NewProp_InteractingActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::NewProp_InteractingActor = { "InteractingActor", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_QuestSystemPlugin_eventOnActorInteract_Parms, InteractingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::NewProp_InteractingActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::NewProp_InteractingActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::NewProp_InteractingActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_QuestSystemPlugin, nullptr, "OnActorInteract__DelegateSignature", nullptr, nullptr, sizeof(_Script_QuestSystemPlugin_eventOnActorInteract_Parms), Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_QuestSystemPlugin_OnActorInteract__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics
	{
		struct _Script_QuestSystemPlugin_eventOnEnemyKill_Parms
		{
			const AActor* KilledActor;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KilledActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_KilledActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::NewProp_KilledActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::NewProp_KilledActor = { "KilledActor", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_QuestSystemPlugin_eventOnEnemyKill_Parms, KilledActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::NewProp_KilledActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::NewProp_KilledActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::NewProp_KilledActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_QuestSystemPlugin, nullptr, "OnEnemyKill__DelegateSignature", nullptr, nullptr, sizeof(_Script_QuestSystemPlugin_eventOnEnemyKill_Parms), Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_QuestSystemPlugin_OnEnemyKill__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
class UScriptStruct* FQuestManagerInitializer::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern QUESTSYSTEMPLUGIN_API uint32 Get_Z_Construct_UScriptStruct_FQuestManagerInitializer_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FQuestManagerInitializer, Z_Construct_UPackage__Script_QuestSystemPlugin(), TEXT("QuestManagerInitializer"), sizeof(FQuestManagerInitializer), Get_Z_Construct_UScriptStruct_FQuestManagerInitializer_Hash());
	}
	return Singleton;
}
template<> QUESTSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FQuestManagerInitializer>()
{
	return FQuestManagerInitializer::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FQuestManagerInitializer(FQuestManagerInitializer::StaticStruct, TEXT("/Script/QuestSystemPlugin"), TEXT("QuestManagerInitializer"), false, nullptr, nullptr);
static struct FScriptStruct_QuestSystemPlugin_StaticRegisterNativesFQuestManagerInitializer
{
	FScriptStruct_QuestSystemPlugin_StaticRegisterNativesFQuestManagerInitializer()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("QuestManagerInitializer")),new UScriptStruct::TCppStructOps<FQuestManagerInitializer>);
	}
} ScriptStruct_QuestSystemPlugin_StaticRegisterNativesFQuestManagerInitializer;
	struct Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FQuestManagerInitializer>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
		nullptr,
		&NewStructOps,
		"QuestManagerInitializer",
		sizeof(FQuestManagerInitializer),
		alignof(FQuestManagerInitializer),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FQuestManagerInitializer()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FQuestManagerInitializer_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_QuestSystemPlugin();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("QuestManagerInitializer"), sizeof(FQuestManagerInitializer), Get_Z_Construct_UScriptStruct_FQuestManagerInitializer_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FQuestManagerInitializer_Hash() { return 179414597U; }
class UScriptStruct* FQuestDelegates::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern QUESTSYSTEMPLUGIN_API uint32 Get_Z_Construct_UScriptStruct_FQuestDelegates_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FQuestDelegates, Z_Construct_UPackage__Script_QuestSystemPlugin(), TEXT("QuestDelegates"), sizeof(FQuestDelegates), Get_Z_Construct_UScriptStruct_FQuestDelegates_Hash());
	}
	return Singleton;
}
template<> QUESTSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FQuestDelegates>()
{
	return FQuestDelegates::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FQuestDelegates(FQuestDelegates::StaticStruct, TEXT("/Script/QuestSystemPlugin"), TEXT("QuestDelegates"), false, nullptr, nullptr);
static struct FScriptStruct_QuestSystemPlugin_StaticRegisterNativesFQuestDelegates
{
	FScriptStruct_QuestSystemPlugin_StaticRegisterNativesFQuestDelegates()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("QuestDelegates")),new UScriptStruct::TCppStructOps<FQuestDelegates>);
	}
} ScriptStruct_QuestSystemPlugin_StaticRegisterNativesFQuestDelegates;
	struct Z_Construct_UScriptStruct_FQuestDelegates_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestDelegates_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FQuestDelegates_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FQuestDelegates>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FQuestDelegates_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
		nullptr,
		&NewStructOps,
		"QuestDelegates",
		sizeof(FQuestDelegates),
		alignof(FQuestDelegates),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FQuestDelegates_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestDelegates_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FQuestDelegates()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FQuestDelegates_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_QuestSystemPlugin();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("QuestDelegates"), sizeof(FQuestDelegates), Get_Z_Construct_UScriptStruct_FQuestDelegates_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FQuestDelegates_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FQuestDelegates_Hash() { return 2998474983U; }
	DEFINE_FUNCTION(UQuestManager::execOnQuestFocusChanged)
	{
		P_GET_OBJECT(UQuest,Z_Param_Quest);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnQuestFocusChanged(Z_Param_Quest);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestManager::execDiscardQuest)
	{
		P_GET_OBJECT(UQuest,Z_Param_Quest);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DiscardQuest(Z_Param_Quest);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestManager::execTakeQuest)
	{
		P_GET_OBJECT(UQuest,Z_Param_Quest);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TakeQuest(Z_Param_Quest);
		P_NATIVE_END;
	}
	void UQuestManager::StaticRegisterNativesUQuestManager()
	{
		UClass* Class = UQuestManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DiscardQuest", &UQuestManager::execDiscardQuest },
			{ "OnQuestFocusChanged", &UQuestManager::execOnQuestFocusChanged },
			{ "TakeQuest", &UQuestManager::execTakeQuest },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics
	{
		struct QuestManager_eventDiscardQuest_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::NewProp_Quest = { "Quest", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(QuestManager_eventDiscardQuest_Parms, Quest), Z_Construct_UClass_UQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::NewProp_Quest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestManager, nullptr, "DiscardQuest", nullptr, nullptr, sizeof(QuestManager_eventDiscardQuest_Parms), Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestManager_DiscardQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestManager_DiscardQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics
	{
		struct QuestManager_eventOnQuestFocusChanged_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::NewProp_Quest = { "Quest", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(QuestManager_eventOnQuestFocusChanged_Parms, Quest), Z_Construct_UClass_UQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::NewProp_Quest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestManager, nullptr, "OnQuestFocusChanged", nullptr, nullptr, sizeof(QuestManager_eventOnQuestFocusChanged_Parms), Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestManager_TakeQuest_Statics
	{
		struct QuestManager_eventTakeQuest_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::NewProp_Quest = { "Quest", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(QuestManager_eventTakeQuest_Parms, Quest), Z_Construct_UClass_UQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::NewProp_Quest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestManager, nullptr, "TakeQuest", nullptr, nullptr, sizeof(QuestManager_eventTakeQuest_Parms), Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestManager_TakeQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestManager_TakeQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuestManager_NoRegister()
	{
		return UQuestManager::StaticClass();
	}
	struct Z_Construct_UClass_UQuestManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TakenQuestsList_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TakenQuestsList_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TakenQuestsList;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestManager_DiscardQuest, "DiscardQuest" }, // 1412878375
		{ &Z_Construct_UFunction_UQuestManager_OnQuestFocusChanged, "OnQuestFocusChanged" }, // 3990973877
		{ &Z_Construct_UFunction_UQuestManager_TakeQuest, "TakeQuest" }, // 2784408432
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/QuestManager.h" },
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuestsList_Inner = { "TakenQuestsList", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UQuest_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuestsList_MetaData[] = {
		{ "ModuleRelativePath", "Public/Core/QuestManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuestsList = { "TakenQuestsList", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuestManager, TakenQuestsList), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuestsList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuestsList_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuestsList_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestManager_Statics::NewProp_TakenQuestsList,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestManager_Statics::ClassParams = {
		&UQuestManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestManager, 709329112);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UQuestManager>()
	{
		return UQuestManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestManager(Z_Construct_UClass_UQuestManager, &UQuestManager::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UQuestManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
