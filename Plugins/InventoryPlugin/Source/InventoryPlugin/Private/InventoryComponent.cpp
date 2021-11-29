#include "InventoryComponent.h"
#include "InventoryStructs.h"


UInventoryComponent::UInventoryComponent() {
	
}

bool UInventoryComponent::AddItem(const FItemInfo& ItemInfo, const int32& RequiredSlot, const bool& bIsReplacePrevious) {
	if(StoredItemInfo.Contains(RequiredSlot)) {
		if(!bIsReplacePrevious)
			return false;
		else {
			Clear(RequiredSlot);
			AddItem(ItemInfo, RequiredSlot, bIsReplacePrevious);
		}
	}
	else if(RequiredSlot > 0 && RequiredSlot < FixedSize)
		StoredItemInfo.Add(RequiredSlot, ItemInfo);
	else {
		int32 EmptySlot = GetEmptySlot();

		if(EmptySlot > 0)
			StoredItemInfo.Add(EmptySlot, ItemInfo);
	}

	return true;
}

bool UInventoryComponent::MoveItem(const int32& SlotFrom, const int32& SlotTo, const bool& bIsForced) {
	if(!StoredItemInfo.Contains(SlotFrom))
		return false;

	if(StoredItemInfo.Contains(SlotTo)) {
		if(bIsForced) 
			Swap(StoredItemInfo[SlotFrom], StoredItemInfo[SlotTo]);
	}
	else
		return AddItem(StoredItemInfo[SlotFrom], SlotTo, bIsForced);

	
	return true;
}

void UInventoryComponent::AddCash(const int32& Value) {
	CashQuantity += Value;

	if(OnMoneyReceive.IsBound())
		OnMoneyReceive.Broadcast(Value);
}

bool UInventoryComponent::GetItem(const int32& RequiredSlot, FItemInfo* StructToSet) {
	if(!StoredItemInfo.Contains(RequiredSlot))
		return false;

	*StructToSet = StoredItemInfo[RequiredSlot];

	return true;
}

TMap<int32, FItemInfo> UInventoryComponent::GetItems() const {
	return StoredItemInfo;
}

int32 UInventoryComponent::GetCashQuantity() const {
	return CashQuantity;
}

int32 UInventoryComponent::GetItemsLimit() const {
	return FixedSize;
}

void UInventoryComponent::Clear(const int32& RequiredSlot) {
	if(StoredItemInfo.Contains(RequiredSlot))
		StoredItemInfo.Remove(RequiredSlot);
}

void UInventoryComponent::Init(TArray<FItemInfo> RequiredItems, const int32& Size) {
	FixedSize = Size;

	for(auto Item : RequiredItems)
		AddItem(Item);
}

void UInventoryComponent::SetFixedSize(const int32 Size) {
	FixedSize = Size;
}

int32 UInventoryComponent::GetSlotItemsLimit(const int32& Slot) const {
	return -1;
}

void UInventoryComponent::SetItemsQuantity(const int32& Value, const int32& RequiredSlot) {
	if(!StoredItemInfo.Contains(RequiredSlot))
		return;

	StoredItemInfo[RequiredSlot].ItemQuantity = Value;

	if(StoredItemInfo[RequiredSlot].ItemQuantity < 1)
		Clear(RequiredSlot);
}

void UInventoryComponent::IncrementItemQuantity(const int32& RequiredSlot, const int32& Value) {
	if(!StoredItemInfo.Contains(RequiredSlot))
		return;

	SetItemsQuantity(StoredItemInfo[RequiredSlot].ItemQuantity + Value, RequiredSlot);
}

void UInventoryComponent::BeginDestroy() {
	Super::BeginDestroy();
}

int32 UInventoryComponent::GetEmptySlot() const {
	for(int Slot = 0; Slot < FixedSize; ++Slot)
		if(!StoredItemInfo.Contains(Slot)) 
			return Slot;

	return -1;
}