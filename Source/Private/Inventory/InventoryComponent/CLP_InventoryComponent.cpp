// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Inventory/InventoryComponent/CLP_InventoryComponent.h"
#include <iostream>
#include <algorithm>

/*-------------------------------------------------------------------------*/
/*  Constructor/Destructor                                                */
/*-------------------------------------------------------------------------*/
CLP_InventoryComponent::CLP_InventoryComponent()
{
}

CLP_InventoryComponent::~CLP_InventoryComponent()
{
}

/*-------------------------------------------------------------------------*/
/*  Core Inventory Functions                                              */
/*-------------------------------------------------------------------------*/
void CLP_InventoryComponent::ListItems() const
{
    if (Items.empty())
    {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }
    
    std::cout << "\n=== Inventory ===" << std::endl;
    for (const auto& item : Items)
    {
        if (item.IsValid())
        {
            std::cout << "- " << item.Name 
                     << " (x" << item.StackCount << ")" << std::endl;
        }
    }
    std::cout << "================" << std::endl;
}

bool CLP_InventoryComponent::AddItem(int ItemID, const string& ItemName, const string& ItemDescription, int Amount)
{
    if (Amount <= 0) return false;
    
    // Check if item already exists in inventory
    CLP_ItemData* existingItem = FindItem(ItemName);
    if (existingItem)
    {
        existingItem->StackCount += Amount;
        std::cout << "Added " << Amount << " " << ItemName << "(s) to inventory." << std::endl;
        return true;
    }
    
    // Create new item and add to inventory
    CLP_ItemData newItem(ItemID, ItemName, ItemDescription, Amount);
    Items.push_back(newItem);
    
    std::cout << "Added " << Amount << " " << ItemName << "(s) to inventory." << std::endl;
    return true;
}

bool CLP_InventoryComponent::RemoveItem(const string& ItemName, int Amount)
{
    if (Amount <= 0) return false;
    
    // Find item in inventory
    auto it = std::find_if(Items.begin(), Items.end(),
        [&ItemName](const CLP_ItemData& item)
        {
            return item.IsValid() && item.Name == ItemName;
        });
    
    if (it == Items.end())
    {
        std::cout << "Item not found in inventory: " << ItemName << std::endl;
        return false;
    }
    
    if (it->StackCount < Amount)
    {
        std::cout << "Not enough " << ItemName << " in inventory. Have: " 
                 << it->StackCount << ", Need: " << Amount << std::endl;
        return false;
    }
    
    it->StackCount -= Amount;
    std::cout << "Removed " << Amount << " " << ItemName << "(s) from inventory." << std::endl;
    
    // Remove item completely if stack count reaches 0
    if (it->StackCount <= 0)
    {
        Items.erase(it);
    }
    
    return true;
}

bool CLP_InventoryComponent::InspectItem(const string& ItemName) const
{
    const CLP_ItemData* item = FindItem(ItemName);
    if (!item)
    {
        std::cout << "Item not found in inventory: " << ItemName << std::endl;
        return false;
    }
    
    std::cout << "\n=== Item Details ===" << std::endl;
    std::cout << "ID: " << item->ID << std::endl;
    std::cout << "Name: " << item->Name << std::endl;
    std::cout << "Amount: " << item->StackCount << std::endl;
    std::cout << "Description: " << item->Description << std::endl;
    std::cout << "===================" << std::endl;
    
    return true;
}

/*-------------------------------------------------------------------------*/
/*  Utility Functions                                                     */
/*-------------------------------------------------------------------------*/
int CLP_InventoryComponent::GetItemCount(const string& ItemName) const
{
    const CLP_ItemData* item = FindItem(ItemName);
    return item ? item->StackCount : 0;
}

bool CLP_InventoryComponent::HasItem(const string& ItemName) const
{
    return FindItem(ItemName) != nullptr;
}

void CLP_InventoryComponent::ClearInventory()
{
    Items.clear();
    std::cout << "Inventory cleared." << std::endl;
}

/*-------------------------------------------------------------------------*/
/*  Helper Functions                                                      */
/*-------------------------------------------------------------------------*/
CLP_ItemData* CLP_InventoryComponent::FindItem(const string& ItemName)
{
    auto it = std::find_if(Items.begin(), Items.end(),
        [&ItemName](const CLP_ItemData& item)
        {
            return item.IsValid() && item.Name == ItemName;
        });
    
    return (it != Items.end()) ? &(*it) : nullptr;
}

const CLP_ItemData* CLP_InventoryComponent::FindItem(const string& ItemName) const
{
    auto it = std::find_if(Items.begin(), Items.end(),
        [&ItemName](const CLP_ItemData& item)
        {
            return item.IsValid() && item.Name == ItemName;
        });
    
    return (it != Items.end()) ? &(*it) : nullptr;
}
/*-------------------------------------------------------------------------*/