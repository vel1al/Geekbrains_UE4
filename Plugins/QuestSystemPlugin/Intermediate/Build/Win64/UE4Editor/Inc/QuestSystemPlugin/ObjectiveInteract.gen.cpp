// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Objectives/ObjectiveInteract.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveInteract() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveInteract_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveInteract();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UObjectiveInteract::execOnInteract)
	{
		P_GET_OBJECT(AActor,Z_Param_InteractingActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnInteract(Z_Param_InteractingActor);
		P_NATIVE_END;
	}
	void UObjectiveInteract::StaticRegisterNativesUObjectiveInteract()
	{
		UClass* Class = UObjectiveInteract::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnInteract", &UObjectiveInteract::execOnInteract },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics
	{
		struct ObjectiveInteract_eventOnInteract_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::NewProp_InteractingActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::NewProp_InteractingActor = { "InteractingActor", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectiveInteract_eventOnInteract_Parms, InteractingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::NewProp_InteractingActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::NewProp_InteractingActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::NewProp_InteractingActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveInteract.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectiveInteract, nullptr, "OnInteract", nullptr, nullptr, sizeof(ObjectiveInteract_eventOnInteract_Parms), Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectiveInteract_OnInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectiveInteract_OnInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UObjectiveInteract_NoRegister()
	{
		return UObjectiveInteract::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveInteract_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetActorInteractedWith_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TargetActorInteractedWith;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveInteract_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObjective,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UObjectiveInteract_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UObjectiveInteract_OnInteract, "OnInteract" }, // 3340240805
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveInteract_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objectives/ObjectiveInteract.h" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveInteract.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveInteract_Statics::NewProp_TargetActorInteractedWith_MetaData[] = {
		{ "Category", "ObjectiveInteract" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveInteract.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectiveInteract_Statics::NewProp_TargetActorInteractedWith = { "TargetActorInteractedWith", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveInteract, TargetActorInteractedWith), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UObjectiveInteract_Statics::NewProp_TargetActorInteractedWith_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveInteract_Statics::NewProp_TargetActorInteractedWith_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectiveInteract_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveInteract_Statics::NewProp_TargetActorInteractedWith,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveInteract_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveInteract>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveInteract_Statics::ClassParams = {
		&UObjectiveInteract::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UObjectiveInteract_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveInteract_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveInteract_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveInteract_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveInteract()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveInteract_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveInteract, 1313457475);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjectiveInteract>()
	{
		return UObjectiveInteract::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveInteract(Z_Construct_UClass_UObjectiveInteract, &UObjectiveInteract::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjectiveInteract"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveInteract);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
