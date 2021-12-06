// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef QUESTSYSTEMPLUGIN_ObjectiveKill_generated_h
#error "ObjectiveKill.generated.h already included, missing '#pragma once' in ObjectiveKill.h"
#endif
#define QUESTSYSTEMPLUGIN_ObjectiveKill_generated_h

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_SPARSE_DATA
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnKill);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnKill);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUObjectiveKill(); \
	friend struct Z_Construct_UClass_UObjectiveKill_Statics; \
public: \
	DECLARE_CLASS(UObjectiveKill, UObjective, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UObjectiveKill)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUObjectiveKill(); \
	friend struct Z_Construct_UClass_UObjectiveKill_Statics; \
public: \
	DECLARE_CLASS(UObjectiveKill, UObjective, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UObjectiveKill)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectiveKill(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectiveKill) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectiveKill); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectiveKill); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectiveKill(UObjectiveKill&&); \
	NO_API UObjectiveKill(const UObjectiveKill&); \
public:


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectiveKill(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectiveKill(UObjectiveKill&&); \
	NO_API UObjectiveKill(const UObjectiveKill&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectiveKill); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectiveKill); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectiveKill)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetToKill() { return STRUCT_OFFSET(UObjectiveKill, TargetToKill); } \
	FORCEINLINE static uint32 __PPO__bIsCountKills() { return STRUCT_OFFSET(UObjectiveKill, bIsCountKills); } \
	FORCEINLINE static uint32 __PPO__TargetKillsCount() { return STRUCT_OFFSET(UObjectiveKill, TargetKillsCount); }


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_12_PROLOG
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_RPC_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_INCLASS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_INCLASS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<class UObjectiveKill>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveKill_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
