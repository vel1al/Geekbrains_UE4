// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UQuest;
#ifdef QUESTSYSTEMPLUGIN_QuestManager_generated_h
#error "QuestManager.generated.h already included, missing '#pragma once' in QuestManager.h"
#endif
#define QUESTSYSTEMPLUGIN_QuestManager_generated_h

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_38_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FQuestManagerInitializer_Statics; \
	QUESTSYSTEMPLUGIN_API static class UScriptStruct* StaticStruct();


template<> QUESTSYSTEMPLUGIN_API UScriptStruct* StaticStruct<struct FQuestManagerInitializer>();

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_26_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FQuestDelegates_Statics; \
	QUESTSYSTEMPLUGIN_API static class UScriptStruct* StaticStruct();


template<> QUESTSYSTEMPLUGIN_API UScriptStruct* StaticStruct<struct FQuestDelegates>();

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_14_DELEGATE \
struct _Script_QuestSystemPlugin_eventOnMoneyReceive_Parms \
{ \
	int32 MoneyValue; \
}; \
static inline void FOnMoneyReceive_DelegateWrapper(const FMulticastScriptDelegate& OnMoneyReceive, int32 MoneyValue) \
{ \
	_Script_QuestSystemPlugin_eventOnMoneyReceive_Parms Parms; \
	Parms.MoneyValue=MoneyValue; \
	OnMoneyReceive.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_13_DELEGATE \
struct _Script_QuestSystemPlugin_eventOnScoreReceive_Parms \
{ \
	int32 ScoreValue; \
}; \
static inline void FOnScoreReceive_DelegateWrapper(const FMulticastScriptDelegate& OnScoreReceive, int32 ScoreValue) \
{ \
	_Script_QuestSystemPlugin_eventOnScoreReceive_Parms Parms; \
	Parms.ScoreValue=ScoreValue; \
	OnScoreReceive.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_12_DELEGATE \
struct _Script_QuestSystemPlugin_eventOnItemCollect_Parms \
{ \
	FName CollectedItem; \
}; \
static inline void FOnItemCollect_DelegateWrapper(const FMulticastScriptDelegate& OnItemCollect, FName CollectedItem) \
{ \
	_Script_QuestSystemPlugin_eventOnItemCollect_Parms Parms; \
	Parms.CollectedItem=CollectedItem; \
	OnItemCollect.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_11_DELEGATE \
struct _Script_QuestSystemPlugin_eventOnActorInteract_Parms \
{ \
	const AActor* InteractingActor; \
}; \
static inline void FOnActorInteract_DelegateWrapper(const FMulticastScriptDelegate& OnActorInteract, const AActor* InteractingActor) \
{ \
	_Script_QuestSystemPlugin_eventOnActorInteract_Parms Parms; \
	Parms.InteractingActor=InteractingActor; \
	OnActorInteract.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_10_DELEGATE \
struct _Script_QuestSystemPlugin_eventOnEnemyKill_Parms \
{ \
	const AActor* KilledActor; \
}; \
static inline void FOnEnemyKill_DelegateWrapper(const FMulticastScriptDelegate& OnEnemyKill, const AActor* KilledActor) \
{ \
	_Script_QuestSystemPlugin_eventOnEnemyKill_Parms Parms; \
	Parms.KilledActor=KilledActor; \
	OnEnemyKill.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_SPARSE_DATA
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnQuestFocusChanged); \
	DECLARE_FUNCTION(execDiscardQuest); \
	DECLARE_FUNCTION(execTakeQuest);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnQuestFocusChanged); \
	DECLARE_FUNCTION(execDiscardQuest); \
	DECLARE_FUNCTION(execTakeQuest);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestManager(); \
	friend struct Z_Construct_UClass_UQuestManager_Statics; \
public: \
	DECLARE_CLASS(UQuestManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UQuestManager)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_INCLASS \
private: \
	static void StaticRegisterNativesUQuestManager(); \
	friend struct Z_Construct_UClass_UQuestManager_Statics; \
public: \
	DECLARE_CLASS(UQuestManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UQuestManager)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestManager(UQuestManager&&); \
	NO_API UQuestManager(const UQuestManager&); \
public:


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestManager() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestManager(UQuestManager&&); \
	NO_API UQuestManager(const UQuestManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UQuestManager)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TakenQuestsList() { return STRUCT_OFFSET(UQuestManager, TakenQuestsList); }


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_49_PROLOG
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_RPC_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_INCLASS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_INCLASS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<class UQuestManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
