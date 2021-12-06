// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Objectives/ObjectiveKill.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectiveKill() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveKill_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjectiveKill();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UObjective();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UObjectiveKill::execOnKill)
	{
		P_GET_OBJECT(AActor,Z_Param_KilledActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnKill(Z_Param_KilledActor);
		P_NATIVE_END;
	}
	void UObjectiveKill::StaticRegisterNativesUObjectiveKill()
	{
		UClass* Class = UObjectiveKill::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnKill", &UObjectiveKill::execOnKill },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UObjectiveKill_OnKill_Statics
	{
		struct ObjectiveKill_eventOnKill_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::NewProp_KilledActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::NewProp_KilledActor = { "KilledActor", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ObjectiveKill_eventOnKill_Parms, KilledActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::NewProp_KilledActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::NewProp_KilledActor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::NewProp_KilledActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveKill.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UObjectiveKill, nullptr, "OnKill", nullptr, nullptr, sizeof(ObjectiveKill_eventOnKill_Parms), Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UObjectiveKill_OnKill()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UObjectiveKill_OnKill_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UObjectiveKill_NoRegister()
	{
		return UObjectiveKill::StaticClass();
	}
	struct Z_Construct_UClass_UObjectiveKill_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetToKill_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TargetToKill;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsCountKills_MetaData[];
#endif
		static void NewProp_bIsCountKills_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsCountKills;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetKillsCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TargetKillsCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UObjectiveKill_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObjective,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UObjectiveKill_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UObjectiveKill_OnKill, "OnKill" }, // 3902378843
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveKill_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Objectives/ObjectiveKill.h" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveKill.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetToKill_MetaData[] = {
		{ "Category", "ObjectiveKill" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveKill.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetToKill = { "TargetToKill", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveKill, TargetToKill), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetToKill_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetToKill_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveKill_Statics::NewProp_bIsCountKills_MetaData[] = {
		{ "Category", "ObjectiveKill" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveKill.h" },
	};
#endif
	void Z_Construct_UClass_UObjectiveKill_Statics::NewProp_bIsCountKills_SetBit(void* Obj)
	{
		((UObjectiveKill*)Obj)->bIsCountKills = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UObjectiveKill_Statics::NewProp_bIsCountKills = { "bIsCountKills", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UObjectiveKill), &Z_Construct_UClass_UObjectiveKill_Statics::NewProp_bIsCountKills_SetBit, METADATA_PARAMS(Z_Construct_UClass_UObjectiveKill_Statics::NewProp_bIsCountKills_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveKill_Statics::NewProp_bIsCountKills_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetKillsCount_MetaData[] = {
		{ "Category", "ObjectiveKill" },
		{ "EditCondition", "bIsCountKills" },
		{ "ModuleRelativePath", "Public/Objectives/ObjectiveKill.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetKillsCount = { "TargetKillsCount", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UObjectiveKill, TargetKillsCount), METADATA_PARAMS(Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetKillsCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetKillsCount_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UObjectiveKill_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetToKill,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveKill_Statics::NewProp_bIsCountKills,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UObjectiveKill_Statics::NewProp_TargetKillsCount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UObjectiveKill_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UObjectiveKill>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UObjectiveKill_Statics::ClassParams = {
		&UObjectiveKill::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UObjectiveKill_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveKill_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UObjectiveKill_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UObjectiveKill_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UObjectiveKill()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UObjectiveKill_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UObjectiveKill, 2746155141);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UObjectiveKill>()
	{
		return UObjectiveKill::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UObjectiveKill(Z_Construct_UClass_UObjectiveKill, &UObjectiveKill::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UObjectiveKill"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UObjectiveKill);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
