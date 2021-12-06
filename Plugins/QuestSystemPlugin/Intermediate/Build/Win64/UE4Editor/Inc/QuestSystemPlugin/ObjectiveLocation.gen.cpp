// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Objectives/ObjectiveLocation.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveLocation() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveLocation_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveLocation();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UObjectiveLocation::execOnOverlap)
	{
		P_GET_OBJECT(AActor,Z_Param_OverlappingActor);
		P_GET_OBJECT(AActor,Z_Param_SelfActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlap(Z_Param_OverlappingActor,Z_Param_SelfActor);
		P_NATIVE_END;
	}
	void UObjectiveLocation::StaticRegisterNativesUObjectiveLocation()
	{
		UClass* Class = UObjectiveLocation::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlap", &UObjectiveLocation::execOnOverlap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics
	{
		struct ObjectiveLocation_eventOnOverlap_Parms
		{
			AActor* OverlappingActor;
			AActor* SelfActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappingActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelfActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::NewProp_OverlappingActor = { "OverlappingActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectiveLocation_eventOnOverlap_Parms, OverlappingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::NewProp_SelfActor = { "SelfActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectiveLocation_eventOnOverlap_Parms, SelfActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::NewProp_OverlappingActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::NewProp_SelfActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveLocation.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectiveLocation, nullptr, "OnOverlap", nullptr, nullptr, sizeof(ObjectiveLocation_eventOnOverlap_Parms), Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectiveLocation_OnOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectiveLocation_OnOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UObjectiveLocation_NoRegister()
	{
		return UObjectiveLocation::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveLocation_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocationActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LocationActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveLocation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObjective,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UObjectiveLocation_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UObjectiveLocation_OnOverlap, "OnOverlap" }, // 3076481018
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveLocation_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objectives/ObjectiveLocation.h" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveLocation.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveLocation_Statics::NewProp_LocationActor_MetaData[] = {
		{ "Category", "ObjectiveLocation" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveLocation.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectiveLocation_Statics::NewProp_LocationActor = { "LocationActor", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveLocation, LocationActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UObjectiveLocation_Statics::NewProp_LocationActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveLocation_Statics::NewProp_LocationActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectiveLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveLocation_Statics::NewProp_LocationActor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveLocation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveLocation>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveLocation_Statics::ClassParams = {
		&UObjectiveLocation::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UObjectiveLocation_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveLocation_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveLocation_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveLocation_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveLocation()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveLocation_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveLocation, 1232003235);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjectiveLocation>()
	{
		return UObjectiveLocation::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveLocation(Z_Construct_UClass_UObjectiveLocation, &UObjectiveLocation::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjectiveLocation"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveLocation);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
