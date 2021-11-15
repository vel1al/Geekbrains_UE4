#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "InventoryStructs.generated.h"


UENUM()
enum class EItemType : uint8{
	Equipment,
	Weapon,
	Consumable,
	Helpers, 
	Material,
	Misc,
	Cash,
	None
};

UENUM()
enum class EItemRarity : uint8{
	Common,
	Uncommon,
	VeryRare,
	Epic,
	Legendary,
	Mystical,
	None
};

USTRUCT()
struct FItemInfo : public FTableRowBase{
		GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FName IDName;
	UPROPERTY(EditAnywhere)
	FText Description;

	UPROPERTY(EditAnywhere)
	EItemType Type;
	UPROPERTY(EditAnywhere)
	EItemRarity Rarity;
		
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2D> Icon;
		
	UPROPERTY()
	int32 ItemQuantity = 1;
		
	bool operator==(const FItemInfo& OtherItem) const{ return IDName == OtherItem.IDName; }
};