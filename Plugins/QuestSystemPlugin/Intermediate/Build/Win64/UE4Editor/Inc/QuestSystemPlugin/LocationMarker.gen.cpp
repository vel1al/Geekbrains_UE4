// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/LocationMarker.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLocationMarker() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_ULocationMarker_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_ULocationMarker();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
// End Cross Module References
	void ULocationMarker::StaticRegisterNativesULocationMarker()
	{
	}
	UClass* Z_Construct_UClass_ULocationMarker_NoRegister()
	{
		return ULocationMarker::StaticClass();
	}
	struct Z_Construct_UClass_ULocationMarker_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULocationMarker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULocationMarker_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LocationMarker.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULocationMarker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ILocationMarker>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULocationMarker_Statics::ClassParams = {
		&ULocationMarker::StaticClass,
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
		0x000040A1u,
		METADATA_PARAMS(Z_Construct_UClass_ULocationMarker_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULocationMarker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULocationMarker()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULocationMarker_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULocationMarker, 2973371396);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<ULocationMarker>()
	{
		return ULocationMarker::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULocationMarker(Z_Construct_UClass_ULocationMarker, &ULocationMarker::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("ULocationMarker"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULocationMarker);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
