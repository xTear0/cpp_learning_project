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
    int32_t Amount;
    
    CLP_ItemComponent()
        : Item(nullptr)
        , Amount(0)
    {}
    
    CLP_ItemComponent(std::unique_ptr<CLP_Item> NewItem, int32_t Count = 1)
        : Item(std::move(NewItem))
        , Amount(Count)
    {}
    
    // Helper functions
    bool IsValid() const { return Item != nullptr && Amount > 0; }
    const std::string& GetItemName() const 
    { 
        static std::string empty = "";
        return Item ? Item->Name : empty; 
    }
    const std::string& GetItemDescription() const 
    { 
        static std::string empty = "";
        return Item ? Item->Description : empty; 
    }
};
/*-------------------------------------------------------------------------*/
