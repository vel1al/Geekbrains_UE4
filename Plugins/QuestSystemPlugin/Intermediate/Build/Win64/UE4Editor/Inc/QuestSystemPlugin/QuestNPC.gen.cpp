// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSystemPlugin/Public/Core/QuestNPC.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestNPC() {}
// Cross Module References
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestNPC_NoRegister();
	QUESTSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UQuestNPC();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_QuestSystemPlugin();
// End Cross Module References
	DEFINE_FUNCTION(IQuestNPC::execGiveQuestCondition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GiveQuestCondition_Implementation();
		P_NATIVE_END;
	}
	bool IQuestNPC::GiveQuestCondition()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GiveQuestCondition instead.");
		QuestNPC_eventGiveQuestCondition_Parms Parms;
		return Parms.ReturnValue;
	}
	void UQuestNPC::StaticRegisterNativesUQuestNPC()
	{
		UClass* Class = UQuestNPC::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GiveQuestCondition", &IQuestNPC::execGiveQuestCondition },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((QuestNPC_eventGiveQuestCondition_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(QuestNPC_eventGiveQuestCondition_Parms), &Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestNPC.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestNPC, nullptr, "GiveQuestCondition", nullptr, nullptr, sizeof(QuestNPC_eventGiveQuestCondition_Parms), Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuestNPC_GiveQuestCondition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UQuestNPC_GiveQuestCondition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UQuestNPC_NoRegister()
	{
		return UQuestNPC::StaticClass();
	}
	struct Z_Construct_UClass_UQuestNPC_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestNPC_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_QuestSystemPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestNPC_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestNPC_GiveQuestCondition, "GiveQuestCondition" }, // 1156999764
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestNPC_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/QuestNPC.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestNPC_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IQuestNPC>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UQuestNPC_Statics::ClassParams = {
		&UQuestNPC::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UQuestNPC_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuestNPC_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuestNPC()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UQuestNPC_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UQuestNPC, 973649561);
	template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<UQuestNPC>()
	{
		return UQuestNPC::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UQuestNPC(Z_Construct_UClass_UQuestNPC, &UQuestNPC::StaticClass, TEXT("/Script/QuestSystemPlugin"), TEXT("UQuestNPC"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestNPC);
	static FName NAME_UQuestNPC_GiveQuestCondition = FName(TEXT("GiveQuestCondition"));
	bool IQuestNPC::Execute_GiveQuestCondition(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UQuestNPC::StaticClass()));
		QuestNPC_eventGiveQuestCondition_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UQuestNPC_GiveQuestCondition);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IQuestNPC*)(O->GetNativeInterfaceAddress(UQuestNPC::StaticClass())))
		{
			Parms.ReturnValue = I->GiveQuestCondition_Implementation();
		}
		return Parms.ReturnValue;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
