// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef QUESTSYSTEMPLUGIN_ObjectiveLocation_generated_h
#error "ObjectiveLocation.generated.h already included, missing '#pragma once' in ObjectiveLocation.h"
#endif
#define QUESTSYSTEMPLUGIN_ObjectiveLocation_generated_h

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_SPARSE_DATA
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlap);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlap);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUObjectiveLocation(); \
	friend struct Z_Construct_UClass_UObjectiveLocation_Statics; \
public: \
	DECLARE_CLASS(UObjectiveLocation, UObjective, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UObjectiveLocation)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUObjectiveLocation(); \
	friend struct Z_Construct_UClass_UObjectiveLocation_Statics; \
public: \
	DECLARE_CLASS(UObjectiveLocation, UObjective, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UObjectiveLocation)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectiveLocation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectiveLocation) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectiveLocation); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectiveLocation); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectiveLocation(UObjectiveLocation&&); \
	NO_API UObjectiveLocation(const UObjectiveLocation&); \
public:


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UObjectiveLocation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UObjectiveLocation(UObjectiveLocation&&); \
	NO_API UObjectiveLocation(const UObjectiveLocation&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UObjectiveLocation); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UObjectiveLocation); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UObjectiveLocation)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__LocationActor() { return STRUCT_OFFSET(UObjectiveLocation, LocationActor); }


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_12_PROLOG
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_RPC_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_INCLASS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_PRIVATE_PROPERTY_OFFSET \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_INCLASS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<class UObjectiveLocation>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Objectives_ObjectiveLocation_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
