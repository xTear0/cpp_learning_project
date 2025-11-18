// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include "../ItemComponent/CLP_ItemComponent.h"
#include <vector>
#include <string>
#include <memory>

/*-------------------------------------------------------------------------*/
/*  Inventory Component                                                   */
/*-------------------------------------------------------------------------*/
class CLP_InventoryComponent
{
public:
    CLP_InventoryComponent();
    ~CLP_InventoryComponent();
    
    // Core inventory functions
    void ListItems() const;
    bool AddItem(const std::string& ItemName, int32_t Amount = 1);
    bool RemoveItem(const std::string& ItemName, int32_t Amount = 1);
    bool InspectItem(const std::string& ItemName) const;
    
    // Utility functions
    int32_t GetItemCount(const std::string& ItemName) const;
    bool HasItem(const std::string& ItemName) const;
    void ClearInventory();
    size_t GetInventorySize() const { return Items.size(); }
    
private:
    std::vector<CLP_ItemComponent> Items;
    
    // Helper functions
    CLP_ItemComponent* FindItem(const std::string& ItemName);
    const CLP_ItemComponent* FindItem(const std::string& ItemName) const;
    std::unique_ptr<CLP_Item> CreateItemByName(const std::string& ItemName) const;
};
/*-------------------------------------------------------------------------*/
