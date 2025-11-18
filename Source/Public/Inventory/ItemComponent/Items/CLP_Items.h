// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include <string>

/*-------------------------------------------------------------------------*/
/*  Item Base Struct                                                      */
/*-------------------------------------------------------------------------*/
struct CLP_Item
{
    std::string Name;
    std::string Description;
    
    CLP_Item() 
        : Name("Unknown Item")
        , Description("No description available") 
    {}
    
    CLP_Item(const std::string& ItemName, const std::string& ItemDesc)
        : Name(ItemName)
        , Description(ItemDesc)
    {}
    
    virtual ~CLP_Item() {}
};

/*-------------------------------------------------------------------------*/
/*  Predefined Items                                                      */
/*-------------------------------------------------------------------------*/
struct CLP_RedPotion : public CLP_Item
{
    float HealAmount;
    
    CLP_RedPotion() 
        : CLP_Item("Red Potion", "A healing potion that restores health.")
        , HealAmount(50.0f)
    {}
};

struct CLP_BlueberryMuffin : public CLP_Item
{
    float HungerRestore;
    
    CLP_BlueberryMuffin()
        : CLP_Item("Blueberry Muffin", "A delicious muffin that restores hunger.")
        , HungerRestore(25.0f)
    {}
};

struct CLP_SwordOfLegends : public CLP_Item
{
    float AttackBonus;
    
    CLP_SwordOfLegends()
        : CLP_Item("Sword of Legends", "A legendary sword with immense power.")
        , AttackBonus(100.0f)
    {}
};
/*-------------------------------------------------------------------------*/
