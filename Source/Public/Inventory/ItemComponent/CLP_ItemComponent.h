// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once
#include "Items/CLP_Items.h"
#include <memory>

/*-------------------------------------------------------------------------*/
/*  Item Component - Container for Items with Stack Count                 */
/*-------------------------------------------------------------------------*/
struct CLP_ItemComponent
{
    std::unique_ptr<CLP_Item> Item;
    int Amount;
    
    CLP_ItemComponent()
        : Item(nullptr)
        , Amount(0)
    {}
    
    CLP_ItemComponent(std::unique_ptr<CLP_Item> NewItem, int Count = 1)
        : Item(std::move(NewItem))
        , Amount(Count)
    {}
    
    // Helper functions
    bool IsValid() const { return Item != nullptr && Amount > 0; }

    // Fetch name
    const std::string& GetItemName() const 
    { 
        static std::string empty = "";
        return Item ? Item->Name : empty; 
    }

    // Fetch description
    const std::string& GetItemDescription() const 
    { 
        static std::string empty = "";
        return Item ? Item->Description : empty; 
    }
};

struct CLP_ItemData
{
    // Getters
    int GetItemID() { return ID; }
    string GetItemName() { return Name; }
    string GetItemDescription() { return Description; }
    int GetItemStackCount() { return StackCount; }

    // Setters
    void BuildItemFromData(
        const int& ID,
        const string& ItemName,
        const string& ItemDescription,
        const int& ItemStackCount);
    
    void SetItemID(const int& InID) { ID = InID; }
    void SetItemName(const string& InName) { Name = InName; }
    void SetItemDescription(const string& InDescription) { Description = InDescription; }
    void SetItemStackCount(const int& Count) { StackCount = Count; }
    
private:
    int ID = 0;
    string Name = "Empty";
    string Description = "Empty";
    int StackCount = 0;
};
/*-------------------------------------------------------------------------*/
