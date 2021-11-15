// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INVENTORYPLUGIN_InventoryStructs_generated_h
#error "InventoryStructs.generated.h already included, missing '#pragma once' in InventoryStructs.h"
#endif
#define INVENTORYPLUGIN_InventoryStructs_generated_h

#define tankogeddon_Plugins_InventoryPlugin_Source_InventoryPlugin_Public_InventoryStructs_h_34_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FItemInfo_Statics; \
	INVENTORYPLUGIN_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> INVENTORYPLUGIN_API UScriptStruct* StaticStruct<struct FItemInfo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tankogeddon_Plugins_InventoryPlugin_Source_InventoryPlugin_Public_InventoryStructs_h


#define FOREACH_ENUM_EITEMRARITY(op) \
	op(EItemRarity::Common) \
	op(EItemRarity::Uncommon) \
	op(EItemRarity::VeryRare) \
	op(EItemRarity::Epic) \
	op(EItemRarity::Legendary) \
	op(EItemRarity::Mystical) \
	op(EItemRarity::None) 

enum class EItemRarity : uint8;
template<> INVENTORYPLUGIN_API UEnum* StaticEnum<EItemRarity>();

#define FOREACH_ENUM_EITEMTYPE(op) \
	op(EItemType::Equipment) \
	op(EItemType::Weapon) \
	op(EItemType::Consumable) \
	op(EItemType::Helpers) \
	op(EItemType::Material) \
	op(EItemType::Misc) \
	op(EItemType::Cash) \
	op(EItemType::None) 

enum class EItemType : uint8;
template<> INVENTORYPLUGIN_API UEnum* StaticEnum<EItemType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
