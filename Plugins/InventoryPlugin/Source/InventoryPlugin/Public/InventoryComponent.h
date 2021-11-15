#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "InventoryStructs.h"
#include "InventoryComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYPLUGIN_API UInventoryComponent : public UActorComponent {
		GENERATED_BODY()
	
	public:
		UInventoryComponent();
	
		bool AddItem(const FItemInfo& ItemInfo, const int32& RequiredSlot = -1, const bool& bIsReplacePrevious = false);
		bool MoveItem(const int32& SlotFrom, const int32& SlotTo, const bool& bIsForced = false);

		void AddCash(const int32& Value);
	
		bool GetItem(const int32& RequiredSlot, FItemInfo* StructToSet);
			
		TMap<int32, FItemInfo> GetItems() const;

		int32 GetCashQuantity() const;
		int32 GetItemsLimit() const;
	
		void Clear(const int32& RequiredSlot);

		void Init(TArray<FItemInfo> RequiredItems, const int32& Size = -1);
		void SetFixedSize(const int32 Size);
	
		virtual int32 GetSlotItemsLimit(const int32& Slot) const;

		void SetItemsQuantity(const int32& Value, const int32& RequiredSlot);
		void IncrementItemQuantity(const int32& RequiredSlot, const int32& Value);
		
	protected:
		virtual void BeginDestroy() override;
	
		int32 GetEmptySlot() const;
	
		int32 CashQuantity = 0;
		int32 FixedSize = 0;
	
		UPROPERTY()
		TMap<int32, FItemInfo> StoredItemInfo;
};