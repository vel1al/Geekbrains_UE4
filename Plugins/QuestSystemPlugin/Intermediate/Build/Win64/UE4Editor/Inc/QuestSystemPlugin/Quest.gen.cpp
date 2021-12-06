// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Core/Quest.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuest() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UEnum* Z_Construct_UEnum_QuestSystemPlugin_EObjectiveType();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuest_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuest();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective_NoRegister();
// End Cross Module References
	static UEnum* EObjectiveType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_QuestSystemPlugin_EObjectiveType, Z_Construct_UPackage__Script_QuestSystemPlugin(), TEXT("EObjectiveType"));
		}
		return Singleton;
	}
	template<> QUESTSYSTEMPLUGIN_API UEnum* StaticEnum<EObjectiveType>()
	{
		return EObjectiveType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EObjectiveType(EObjectiveType_StaticEnum, TEXT("/Script/QuestSystemPlugin"), TEXT("EObjectiveType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_QuestSystemPlugin_EObjectiveType_Hash() { return 3986471714U; }
	UEnum* Z_Construct_UEnum_QuestSystemPlugin_EObjectiveType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_QuestSystemPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EObjectiveType"), 0, Get_Z_Construct_UEnum_QuestSystemPlugin_EObjectiveType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EObjectiveType::Collect", (int64)EObjectiveType::Collect },
				{ "EObjectiveType::Score", (int64)EObjectiveType::Score },
				{ "EObjectiveType::Money", (int64)EObjectiveType::Money },
				{ "EObjectiveType::Kill", (int64)EObjectiveType::Kill },
				{ "EObjectiveType::Interact", (int64)EObjectiveType::Interact },
				{ "EObjectiveType::Location", (int64)EObjectiveType::Location },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Collect.DisplayName", "Collect Item" },
				{ "Collect.Name", "EObjectiveType::Collect" },
				{ "Interact.DisplayName", "Interact with" },
				{ "Interact.Name", "EObjectiveType::Interact" },
				{ "Kill.DisplayName", "Kill enemys" },
				{ "Kill.Name", "EObjectiveType::Kill" },
				{ "Location.DisplayName", "Navigate to" },
				{ "Location.Name", "EObjectiveType::Location" },
				{ "ModuleRelativePath", "Public/Core/Quest.h" },
				{ "Money.DisplayName", "Receive Money" },
				{ "Money.Name", "EObjectiveType::Money" },
				{ "Score.DisplayName", "Receive Score" },
				{ "Score.Name", "EObjectiveType::Score" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
				nullptr,
				"EObjectiveType",
				"EObjectiveType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(UQuest::execOnObjectiveCompleted)
	{
		P_GET_OBJECT(UObjective,Z_Param_CompletedObjective);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnObjectiveCompleted(Z_Param_CompletedObjective);
		P_NATIVE_END;
	}
	void UQuest::StaticRegisterNativesUQuest()
	{
		UClass* Class = UQuest::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnObjectiveCompleted", &UQuest::execOnObjectiveCompleted },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics
	{
		struct Quest_eventOnObjectiveCompleted_Parms
		{
			const UObjective* CompletedObjective;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CompletedObjective_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CompletedObjective;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::NewProp_CompletedObjective_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::NewProp_CompletedObjective = { "CompletedObjective", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Quest_eventOnObjectiveCompleted_Parms, CompletedObjective), Z_Construct_UClass_UObjective_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::NewProp_CompletedObjective_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::NewProp_CompletedObjective_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::NewProp_CompletedObjective,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuest, nullptr, "OnObjectiveCompleted", nullptr, nullptr, sizeof(Quest_eventOnObjectiveCompleted_Parms), Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuest_OnObjectiveCompleted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuest_OnObjectiveCompleted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuest_NoRegister()
	{
		return UQuest::StaticClass();
	}
	struct Z_Construct_UClass_UQuest_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ObjectiveTypeToCreate_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectiveTypeToCreate_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ObjectiveTypeToCreate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Description;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsStoryQuest_MetaData[];
#endif
		static void NewProp_bIsStoryQuest_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsStoryQuest;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PreviousQuest_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PreviousQuest;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bKeepObjectivesOrder_MetaData[];
#endif
		static void NewProp_bKeepObjectivesOrder_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bKeepObjectivesOrder;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestObjectives_Inner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_QuestObjectives_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuestObjectives_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_QuestObjectives;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuest_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuest_OnObjectiveCompleted, "OnObjectiveCompleted" }, // 756369091
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "QuestPlugin|Assets" },
		{ "IncludePath", "Core/Quest.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_ObjectiveTypeToCreate_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_ObjectiveTypeToCreate_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_ObjectiveTypeToCreate = { "ObjectiveTypeToCreate", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuest, ObjectiveTypeToCreate), Z_Construct_UEnum_QuestSystemPlugin_EObjectiveType, METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_ObjectiveTypeToCreate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_ObjectiveTypeToCreate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuest, Name), METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuest, Description), METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_Description_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_Description_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_bIsStoryQuest_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	void Z_Construct_UClass_UQuest_Statics::NewProp_bIsStoryQuest_SetBit(void* Obj)
	{
		((UQuest*)Obj)->bIsStoryQuest = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_bIsStoryQuest = { "bIsStoryQuest", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UQuest), &Z_Construct_UClass_UQuest_Statics::NewProp_bIsStoryQuest_SetBit, METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_bIsStoryQuest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_bIsStoryQuest_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_PreviousQuest_MetaData[] = {
		{ "Category", "Quest" },
		{ "EditCondition", "bIsStoreQuest" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_PreviousQuest = { "PreviousQuest", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuest, PreviousQuest), Z_Construct_UClass_UQuest_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_PreviousQuest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_PreviousQuest_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_bKeepObjectivesOrder_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	void Z_Construct_UClass_UQuest_Statics::NewProp_bKeepObjectivesOrder_SetBit(void* Obj)
	{
		((UQuest*)Obj)->bKeepObjectivesOrder = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_bKeepObjectivesOrder = { "bKeepObjectivesOrder", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UQuest), &Z_Construct_UClass_UQuest_Statics::NewProp_bKeepObjectivesOrder_SetBit, METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_bKeepObjectivesOrder_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_bKeepObjectivesOrder_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_Inner_MetaData[] = {
		{ "Category", "Quest" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_Inner = { "QuestObjectives", nullptr, (EPropertyFlags)0x0002000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObjective_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_Inner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_Inner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_MetaData[] = {
		{ "Category", "Quest" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/Quest.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives = { "QuestObjectives", nullptr, (EPropertyFlags)0x002008800000000d, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UQuest, QuestObjectives), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_ObjectiveTypeToCreate_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_ObjectiveTypeToCreate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_Description,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_bIsStoryQuest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_PreviousQuest,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_bKeepObjectivesOrder,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuest_Statics::NewProp_QuestObjectives,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuest>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuest_Statics::ClassParams = {
		&UQuest::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuest_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuest_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuest_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuest_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuest, 3189983639);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UQuest>()
	{
		return UQuest::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuest(Z_Construct_UClass_UQuest, &UQuest::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UQuest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuest);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
