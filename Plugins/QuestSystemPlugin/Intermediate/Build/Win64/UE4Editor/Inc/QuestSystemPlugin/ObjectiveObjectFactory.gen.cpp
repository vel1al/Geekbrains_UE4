// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Core/ObjectiveObjectFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveObjectFactory() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveObjectFactory_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveObjectFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
// End Cross Module References
	void UObjectiveObjectFactory::StaticRegisterNativesUObjectiveObjectFactory()
	{
	}
	UClass* Z_Construct_UClass_UObjectiveObjectFactory_NoRegister()
	{
		return UObjectiveObjectFactory::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveObjectFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveObjectFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveObjectFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/ObjectiveObjectFactory.h" },
		{ "ModuleRelativePath", "Public/Core/ObjectiveObjectFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveObjectFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveObjectFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveObjectFactory_Statics::ClassParams = {
		&UObjectiveObjectFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveObjectFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveObjectFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveObjectFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveObjectFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveObjectFactory, 3466794583);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjectiveObjectFactory>()
	{
		return UObjectiveObjectFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveObjectFactory(Z_Construct_UClass_UObjectiveObjectFactory, &UObjectiveObjectFactory::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjectiveObjectFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveObjectFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
