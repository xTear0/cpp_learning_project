// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include <vector>
#include <string>
#include "Inventory/ItemComponent/CLP_ItemData.h"

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
    bool AddItem(int ItemID, const string& ItemName, const string& ItemDescription, int Amount = 1);
    bool RemoveItem(const string& ItemName, int Amount = 1);
    bool InspectItem(const string& ItemName) const;
    
    // Utility functions
    int GetItemCount(const string& ItemName) const;
    bool HasItem(const string& ItemName) const;
    void ClearInventory();
    size_t GetInventorySize() const { return Items.size(); }
    
private:
    vector<CLP_ItemData> Items;
    
    // Helper functions
    CLP_ItemData* FindItem(const string& ItemName);
    const CLP_ItemData* FindItem(const string& ItemName) const;
};
/*-------------------------------------------------------------------------*/