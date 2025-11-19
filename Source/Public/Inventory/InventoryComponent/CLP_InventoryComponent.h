// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include "../ItemComponent/CLP_ItemComponent.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;

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
    bool AddItem(const std::string& ItemName, int Amount = 1);
    bool RemoveItem(const std::string& ItemName, int Amount = 1);
    bool InspectItem(const std::string& ItemName) const;
    
    // Utility functions
    int GetItemCount(const std::string& ItemName) const;
    bool HasItem(const std::string& ItemName) const;
    void ClearInventory();
    size_t GetInventorySize() const { return Items.size(); }
    
private:
    vector<CLP_ItemData> Items;
    
    // Helper functions
    CLP_ItemComponent* FindItem(const std::string& ItemName);
    const CLP_ItemComponent* FindItem(const std::string& ItemName) const;
    static std::unique_ptr<CLP_Item> CreateItemByName(const std::string& ItemName);
    void AddItemByData(int ItemID, string ItemName, string ItemDescription, int Amount = 1);
};
/*-------------------------------------------------------------------------*/
