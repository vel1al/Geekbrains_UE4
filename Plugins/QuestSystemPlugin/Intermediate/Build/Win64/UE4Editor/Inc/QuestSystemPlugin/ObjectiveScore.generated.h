// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTSYSTEMPLUGIN_ObjectiveScore_generated_h
#error "ObjectiveScore.generated.h already included, missing '#pragma once' in ObjectiveScore.h"
#endif
#define QUESTSYSTEMPLUGIN_ObjectiveScore_generated_h

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_SPARSE_DATA
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnScoreReceive);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnScoreReceive);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUObjectiveScore(); \
	friend struct Z_Construct_UClass_UObjectiveScore_Statics; \
public: \
	DECLARE_CLASS(UObjectiveScore, UObjective, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UObjectiveScore)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUObjectiveScore(); \
	friend struct Z_Construct_UClass_UObjectiveScore_Statics; \
public: \
	DECLARE_CLASS(UObjectiveScore, UObjective, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UObjectiveScore)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectiveScore(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectiveScore) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectiveScore); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectiveScore); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectiveScore(UObjectiveScore&&); \
	NO_API UObjectiveScore(const UObjectiveScore&); \
public:


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectiveScore(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectiveScore(UObjectiveScore&&); \
	NO_API UObjectiveScore(const UObjectiveScore&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectiveScore); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectiveScore); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectiveScore)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetScoreCount() { return STRUCT_OFFSET(UObjectiveScore, TargetScoreCount); }


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_11_PROLOG
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_RPC_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_INCLASS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_INCLASS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<class UObjectiveScore>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveScore_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
