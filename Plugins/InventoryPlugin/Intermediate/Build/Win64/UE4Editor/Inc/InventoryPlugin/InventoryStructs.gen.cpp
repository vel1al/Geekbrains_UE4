// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InventoryPlugin/Public/InventoryStructs.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryStructs() {}
// Cross Module References
	INVENTORYPLUGIN_API UEnum* Z_Construct_UEnum_InventoryPlugin_EItemRarity();
	UPackage* Z_Construct_UPackage__Script_InventoryPlugin();
	INVENTORYPLUGIN_API UEnum* Z_Construct_UEnum_InventoryPlugin_EItemType();
	INVENTORYPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FItemInfo();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	static UEnum* EItemRarity_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_InventoryPlugin_EItemRarity, Z_Construct_UPackage__Script_InventoryPlugin(), TEXT("EItemRarity"));
		}
		return Singleton;
	}
	template<> INVENTORYPLUGIN_API UEnum* StaticEnum<EItemRarity>()
	{
		return EItemRarity_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EItemRarity(EItemRarity_StaticEnum, TEXT("/Script/InventoryPlugin"), TEXT("EItemRarity"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_InventoryPlugin_EItemRarity_Hash() { return 1152706555U; }
	UEnum* Z_Construct_UEnum_InventoryPlugin_EItemRarity()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_InventoryPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EItemRarity"), 0, Get_Z_Construct_UEnum_InventoryPlugin_EItemRarity_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EItemRarity::Common", (int64)EItemRarity::Common },
				{ "EItemRarity::Uncommon", (int64)EItemRarity::Uncommon },
				{ "EItemRarity::VeryRare", (int64)EItemRarity::VeryRare },
				{ "EItemRarity::Epic", (int64)EItemRarity::Epic },
				{ "EItemRarity::Legendary", (int64)EItemRarity::Legendary },
				{ "EItemRarity::Mystical", (int64)EItemRarity::Mystical },
				{ "EItemRarity::None", (int64)EItemRarity::None },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Common.Name", "EItemRarity::Common" },
				{ "Epic.Name", "EItemRarity::Epic" },
				{ "Legendary.Name", "EItemRarity::Legendary" },
				{ "ModuleRelativePath", "Public/InventoryStructs.h" },
				{ "Mystical.Name", "EItemRarity::Mystical" },
				{ "None.Name", "EItemRarity::None" },
				{ "Uncommon.Name", "EItemRarity::Uncommon" },
				{ "VeryRare.Name", "EItemRarity::VeryRare" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_InventoryPlugin,
				nullptr,
				"EItemRarity",
				"EItemRarity",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EItemType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_InventoryPlugin_EItemType, Z_Construct_UPackage__Script_InventoryPlugin(), TEXT("EItemType"));
		}
		return Singleton;
	}
	template<> INVENTORYPLUGIN_API UEnum* StaticEnum<EItemType>()
	{
		return EItemType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EItemType(EItemType_StaticEnum, TEXT("/Script/InventoryPlugin"), TEXT("EItemType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_InventoryPlugin_EItemType_Hash() { return 4086690168U; }
	UEnum* Z_Construct_UEnum_InventoryPlugin_EItemType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_InventoryPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EItemType"), 0, Get_Z_Construct_UEnum_InventoryPlugin_EItemType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EItemType::Equipment", (int64)EItemType::Equipment },
				{ "EItemType::Weapon", (int64)EItemType::Weapon },
				{ "EItemType::Consumable", (int64)EItemType::Consumable },
				{ "EItemType::Helpers", (int64)EItemType::Helpers },
				{ "EItemType::Material", (int64)EItemType::Material },
				{ "EItemType::Misc", (int64)EItemType::Misc },
				{ "EItemType::Cash", (int64)EItemType::Cash },
				{ "EItemType::None", (int64)EItemType::None },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Cash.Name", "EItemType::Cash" },
				{ "Consumable.Name", "EItemType::Consumable" },
				{ "Equipment.Name", "EItemType::Equipment" },
				{ "Helpers.Name", "EItemType::Helpers" },
				{ "Material.Name", "EItemType::Material" },
				{ "Misc.Name", "EItemType::Misc" },
				{ "ModuleRelativePath", "Public/InventoryStructs.h" },
				{ "None.Name", "EItemType::None" },
				{ "Weapon.Name", "EItemType::Weapon" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_InventoryPlugin,
				nullptr,
				"EItemType",
				"EItemType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}

static_assert(std::is_polymorphic<FItemInfo>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FItemInfo cannot be polymorphic unless super FTableRowBase is polymorphic");

class UScriptStruct* FItemInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern INVENTORYPLUGIN_API uint32 Get_Z_Construct_UScriptStruct_FItemInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemInfo, Z_Construct_UPackage__Script_InventoryPlugin(), TEXT("ItemInfo"), sizeof(FItemInfo), Get_Z_Construct_UScriptStruct_FItemInfo_Hash());
	}
	return Singleton;
}
template<> INVENTORYPLUGIN_API UScriptStruct* StaticStruct<FItemInfo>()
{
	return FItemInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FItemInfo(FItemInfo::StaticStruct, TEXT("/Script/InventoryPlugin"), TEXT("ItemInfo"), false, nullptr, nullptr);
static struct FScriptStruct_InventoryPlugin_StaticRegisterNativesFItemInfo
{
	FScriptStruct_InventoryPlugin_StaticRegisterNativesFItemInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ItemInfo")),new UScriptStruct::TCppStructOps<FItemInfo>);
	}
} ScriptStruct_InventoryPlugin_StaticRegisterNativesFItemInfo;
	struct Z_Construct_UScriptStruct_FItemInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IDName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_IDName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Description;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Type;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Rarity_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rarity_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Rarity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemQuantity_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ItemQuantity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemInfo_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FItemInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_IDName_MetaData[] = {
		{ "Category", "ItemInfo" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_IDName = { "IDName", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemInfo, IDName), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_IDName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_IDName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "ItemInfo" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemInfo, Description), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Description_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Description_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Type_MetaData[] = {
		{ "Category", "ItemInfo" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemInfo, Type), Z_Construct_UEnum_InventoryPlugin_EItemType, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Type_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Type_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Rarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Rarity_MetaData[] = {
		{ "Category", "ItemInfo" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Rarity = { "Rarity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemInfo, Rarity), Z_Construct_UEnum_InventoryPlugin_EItemRarity, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Rarity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Rarity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "ItemInfo" },
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemInfo, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Icon_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Icon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_ItemQuantity_MetaData[] = {
		{ "ModuleRelativePath", "Public/InventoryStructs.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_ItemQuantity = { "ItemQuantity", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemInfo, ItemQuantity), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_ItemQuantity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_ItemQuantity_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_IDName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Description,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Type_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Rarity_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Rarity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_Icon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemInfo_Statics::NewProp_ItemQuantity,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_InventoryPlugin,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"ItemInfo",
		sizeof(FItemInfo),
		alignof(FItemInfo),
		Z_Construct_UScriptStruct_FItemInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FItemInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FItemInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FItemInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_InventoryPlugin();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ItemInfo"), sizeof(FItemInfo), Get_Z_Construct_UScriptStruct_FItemInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FItemInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FItemInfo_Hash() { return 247839034U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
