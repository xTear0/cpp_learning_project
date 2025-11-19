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
    for (const auto& itemComponent : Items)
    {
        if (itemComponent.IsValid())
        {
            std::cout << "- " << itemComponent.GetItemName() 
                     << " (x" << itemComponent.Amount << ")" << std::endl;
        }
    }
    std::cout << "================" << std::endl;
}

bool CLP_InventoryComponent::AddItem(const std::string& ItemName, int32_t Amount)
{
    if (Amount <= 0) return false;
    
    // Check if item already exists in inventory
    CLP_ItemComponent* existingItem = FindItem(ItemName);
    if (existingItem)
    {
        existingItem->Amount += Amount;
        std::cout << "Added " << Amount << " " << ItemName << "(s) to inventory." << std::endl;
        return true;
    }
    
    // Create new item
    std::unique_ptr<CLP_Item> newItem = CreateItemByName(ItemName);
    if (!newItem)
    {
        std::cout << "Unknown item: " << ItemName << std::endl;
        return false;
    }
    
    // Add new item to inventory
    Items.emplace_back(std::move(newItem), Amount);
    std::cout << "Added " << Amount << " " << ItemName << "(s) to inventory." << std::endl;
    return true;
}

bool CLP_InventoryComponent::RemoveItem(const std::string& ItemName, int32_t Amount)
{
    if (Amount <= 0) return false;
    
    // Find item in inventory
    auto it = std::find_if(Items.begin(), Items.end(),
        [&ItemName](const CLP_ItemComponent& component)
        {
            return component.IsValid() && component.GetItemName() == ItemName;
        });
    
    if (it == Items.end())
    {
        std::cout << "Item not found in inventory: " << ItemName << std::endl;
        return false;
    }
    
    if (it->Amount < Amount)
    {
        std::cout << "Not enough " << ItemName << " in inventory. Have: " 
                 << it->Amount << ", Need: " << Amount << std::endl;
        return false;
    }
    
    it->Amount -= Amount;
    std::cout << "Removed " << Amount << " " << ItemName << "(s) from inventory." << std::endl;
    
    // Remove item completely if amount reaches 0
    if (it->Amount <= 0)
    {
        Items.erase(it);
    }
    
    return true;
}

bool CLP_InventoryComponent::InspectItem(const std::string& ItemName) const
{
    const CLP_ItemComponent* itemComponent = FindItem(ItemName);
    if (!itemComponent)
    {
        std::cout << "Item not found in inventory: " << ItemName << std::endl;
        return false;
    }
    
    std::cout << "\n=== Item Details ===" << std::endl;
    std::cout << "Name: " << itemComponent->GetItemName() << std::endl;
    std::cout << "Amount: " << itemComponent->Amount << std::endl;
    std::cout << "Description: " << itemComponent->GetItemDescription() << std::endl;
    std::cout << "===================" << std::endl;
    
    return true;
}

/*-------------------------------------------------------------------------*/
/*  Utility Functions                                                     */
/*-------------------------------------------------------------------------*/
int32_t CLP_InventoryComponent::GetItemCount(const std::string& ItemName) const
{
    const CLP_ItemComponent* item = FindItem(ItemName);
    return item ? item->Amount : 0;
}

bool CLP_InventoryComponent::HasItem(const std::string& ItemName) const
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
CLP_ItemComponent* CLP_InventoryComponent::FindItem(const std::string& ItemName)
{
    auto it = std::find_if(Items.begin(), Items.end(),
        [&ItemName](const CLP_ItemComponent& component)
        {
            return component.IsValid() && component.GetItemName() == ItemName;
        });
    
    return (it != Items.end()) ? &(*it) : nullptr;
}

const CLP_ItemComponent* CLP_InventoryComponent::FindItem(const std::string& ItemName) const
{
    auto it = std::find_if(Items.begin(), Items.end(),
        [&ItemName](const CLP_ItemComponent& component)
        {
            return component.IsValid() && component.GetItemName() == ItemName;
        });
    
    return (it != Items.end()) ? &(*it) : nullptr;
}

std::unique_ptr<CLP_Item> CLP_InventoryComponent::CreateItemByName(const std::string& ItemName)
{
    // Create items based on name
    if (ItemName == "Red Potion")
    {
        return std::make_unique<CLP_RedPotion>();
    }
    else if (ItemName == "Blueberry Muffin")
    {
        return std::make_unique<CLP_BlueberryMuffin>();
    }
    else if (ItemName == "Sword of Legends")
    {
        return std::make_unique<CLP_SwordOfLegends>();
    }
    
    return nullptr;
}

void CLP_InventoryComponent::AddItemByData(int ItemID, string ItemName, string ItemDescription, int Amount)
{
    if (Amount <= 0) return;
    
    // Check if item already exists in inventory
    CLP_ItemData* Item = FindItem(ItemName);
    if (existingItem)
    {
        existingItem->Amount += Amount;
        std::cout << "Added " << Amount << " " << ItemName << "(s) to inventory." << std::endl;
        return;
    }
    
    // Create new item
    CLP_ItemData NewItem;
    NewItem.BuildItemFromData(ItemID, ItemName, ItemDescription, Amount);
    
    if (!newItem)
    {
        std::cout << "Unknown item: " << ItemName << std::endl;
        return;
    }
    
    // Add new item to inventory
    Items.emplace_back(std::move(NewItem));
    
    std::cout << "Added " << Amount << " " << ItemName << "(s) to inventory." << std::endl;
    return;
}

/*-------------------------------------------------------------------------*/
