// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once
#include "../CLP_ItemData.h"

/*-------------------------------------------------------------------------*/
/*  Item Database - Predefined Items                                      */
/*-------------------------------------------------------------------------*/
namespace ItemDatabase
{
    // Item IDs
    enum ItemIDs
    {
        ID_RED_POTION = 1,
        ID_BLUEBERRY_MUFFIN = 2,
        ID_SWORD_OF_LEGENDS = 3
    };
    
    // Predefined Items
    inline CLP_ItemData CreateRedPotion(int Amount = 1)
    {
        return CLP_ItemData(
            ID_RED_POTION,
            "Red Potion",
            "A healing potion that restores 50 health.",
            Amount
        );
    }
    
    inline CLP_ItemData CreateBlueberryMuffin(int Amount = 1)
    {
        return CLP_ItemData(
            ID_BLUEBERRY_MUFFIN,
            "Blueberry Muffin",
            "A delicious muffin that restores 25 hunger.",
            Amount
        );
    }
    
    inline CLP_ItemData CreateSwordOfLegends(int Amount = 1)
    {
        return CLP_ItemData(
            ID_SWORD_OF_LEGENDS,
            "Sword of Legends",
            "A legendary sword with +100 attack power.",
            Amount
        );
    }
}
/*-------------------------------------------------------------------------*/