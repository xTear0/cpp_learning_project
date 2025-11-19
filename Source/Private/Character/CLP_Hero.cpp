// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Character/CLP_Hero.h"

/*-------------------------------------------------------------------------*/
/*  Constructor/Destructor                                                */
/*-------------------------------------------------------------------------*/
CLP_Hero::CLP_Hero()
    : CLP_CharacterBase()
    , Name("Unnamed Hero")
    , Level(1)
    , PlayerClass(EPlayerClass::None)
{
    InventoryComponent = std::make_unique<CLP_InventoryComponent>();
}

CLP_Hero::CLP_Hero(const std::string& PlayerName)
    : CLP_CharacterBase()
    , Name(PlayerName)
    , Level(1)
    , PlayerClass(EPlayerClass::None)
{
    InventoryComponent = std::make_unique<CLP_InventoryComponent>();
}

CLP_Hero::~CLP_Hero()
{
}
/*-------------------------------------------------------------------------*/