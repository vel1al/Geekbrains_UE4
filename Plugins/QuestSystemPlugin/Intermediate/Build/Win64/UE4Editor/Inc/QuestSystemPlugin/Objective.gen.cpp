// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Objectives/Objective.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjective() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
// End Cross Module References
	void UObjective::StaticRegisterNativesUObjective()
	{
	}
	UClass* Z_Construct_UClass_UObjective_NoRegister()
	{
		return UObjective::StaticClass();
	}
	struct Z_Construct_UClass_UObjective_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Description;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RewardForComplete_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RewardForComplete;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjective_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::Class_MetaDataParams[] = {
		{ "Category", "QuestPlugin|Assets" },
		{ "IncludePath", "Objectives/Objective.h" },
		{ "ModuleRelativePath", "Public/Objectives/Objective.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "Objective" },
		{ "ModuleRelativePath", "Public/Objectives/Objective.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_UObjective_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjective, Description), METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::NewProp_Description_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::NewProp_Description_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjective_Statics::NewProp_RewardForComplete_MetaData[] = {
		{ "Category", "Objective" },
		{ "ModuleRelativePath", "Public/Objectives/Objective.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UObjective_Statics::NewProp_RewardForComplete = { "RewardForComplete", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjective, RewardForComplete), METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::NewProp_RewardForComplete_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::NewProp_RewardForComplete_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjective_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjective_Statics::NewProp_Description,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjective_Statics::NewProp_RewardForComplete,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjective_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjective>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjective_Statics::ClassParams = {
		&UObjective::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UObjective_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::PropPointers),
		0,
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UObjective_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjective_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjective()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjective_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjective, 3094631105);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjective>()
	{
		return UObjective::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjective(Z_Construct_UClass_UObjective, &UObjective::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjective"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjective);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
