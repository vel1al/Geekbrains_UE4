// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObjective;
#ifdef QUESTSYSTEMPLUGIN_Quest_generated_h
#error "Quest.generated.h already included, missing '#pragma once' in Quest.h"
#endif
#define QUESTSYSTEMPLUGIN_Quest_generated_h

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_SPARSE_DATA
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnObjectiveCompleted);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnObjectiveCompleted);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuest(); \
	friend struct Z_Construct_UClass_UQuest_Statics; \
public: \
	DECLARE_CLASS(UQuest, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UQuest)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUQuest(); \
	friend struct Z_Construct_UClass_UQuest_Statics; \
public: \
	DECLARE_CLASS(UQuest, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UQuest)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuest(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuest) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuest); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuest(UQuest&&); \
	NO_API UQuest(const UQuest&); \
public:


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuest(UQuest&&); \
	NO_API UQuest(const UQuest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuest); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UQuest)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__QuestObjectives() { return STRUCT_OFFSET(UQuest, QuestObjectives); }


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_26_PROLOG
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_RPC_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_INCLASS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_INCLASS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<class UQuest>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_Quest_h


#define FOREACH_ENUM_EOBJECTIVETYPE(op) \
	op(EObjectiveType::Collect) \
	op(EObjectiveType::Score) \
	op(EObjectiveType::Money) \
	op(EObjectiveType::Kill) \
	op(EObjectiveType::Interact) \
	op(EObjectiveType::Location) 

enum class EObjectiveType : uint8;
template<> QUESTSYSTEMPLUGIN_API UEnum* StaticEnum<EObjectiveType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
