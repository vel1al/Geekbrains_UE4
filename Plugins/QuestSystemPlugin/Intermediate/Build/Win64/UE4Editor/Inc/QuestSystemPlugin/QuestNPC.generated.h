// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QUESTSYSTEMPLUGIN_QuestNPC_generated_h
#error "QuestNPC.generated.h already included, missing '#pragma once' in QuestNPC.h"
#endif
#define QUESTSYSTEMPLUGIN_QuestNPC_generated_h

#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_SPARSE_DATA
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_RPC_WRAPPERS \
	virtual bool GiveQuestCondition_Implementation() { return false; }; \
 \
	DECLARE_FUNCTION(execGiveQuestCondition);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGiveQuestCondition);


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_EVENT_PARMS \
	struct QuestNPC_eventGiveQuestCondition_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		QuestNPC_eventGiveQuestCondition_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_CALLBACK_WRAPPERS
#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	QUESTSYSTEMPLUGIN_API UQuestNPC(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestNPC) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(QUESTSYSTEMPLUGIN_API, UQuestNPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestNPC); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	QUESTSYSTEMPLUGIN_API UQuestNPC(UQuestNPC&&); \
	QUESTSYSTEMPLUGIN_API UQuestNPC(const UQuestNPC&); \
public:


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	QUESTSYSTEMPLUGIN_API UQuestNPC(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	QUESTSYSTEMPLUGIN_API UQuestNPC(UQuestNPC&&); \
	QUESTSYSTEMPLUGIN_API UQuestNPC(const UQuestNPC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(QUESTSYSTEMPLUGIN_API, UQuestNPC); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestNPC); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestNPC)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUQuestNPC(); \
	friend struct Z_Construct_UClass_UQuestNPC_Statics; \
public: \
	DECLARE_CLASS(UQuestNPC, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/QuestSystemPlugin"), QUESTSYSTEMPLUGIN_API) \
	DECLARE_SERIALIZER(UQuestNPC)


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_GENERATED_UINTERFACE_BODY() \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_GENERATED_UINTERFACE_BODY() \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IQuestNPC() {} \
public: \
	typedef UQuestNPC UClassType; \
	typedef IQuestNPC ThisClass; \
	static bool Execute_GiveQuestCondition(UObject* O); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_INCLASS_IINTERFACE \
protected: \
	virtual ~IQuestNPC() {} \
public: \
	typedef UQuestNPC UClassType; \
	typedef IQuestNPC ThisClass; \
	static bool Execute_GiveQuestCondition(UObject* O); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_9_PROLOG \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_EVENT_PARMS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_RPC_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_CALLBACK_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_SPARSE_DATA \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_CALLBACK_WRAPPERS \
	tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> QUESTSYSTEMPLUGIN_API UClass* StaticClass<class UQuestNPC>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tankogeddon_Plugins_QuestSystemPlugin_Source_QuestSystemPlugin_Public_Core_QuestNPC_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS