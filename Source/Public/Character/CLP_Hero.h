// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include "CLP_CharacterBase.h"
#include "../Core/Types/CLP_EnumTypes.h"
#include "../Inventory/InventoryComponent/CLP_InventoryComponent.h"
#include <string>
#include <memory>

/*-------------------------------------------------------------------------*/
/*  Hero (Player) Class                                                   */
/*-------------------------------------------------------------------------*/
class CLP_Hero : public CLP_CharacterBase
{
public:
    CLP_Hero();
    CLP_Hero(const std::string& PlayerName);
    virtual ~CLP_Hero();
    
    // Getters
    const std::string& GetName() const { return Name; }
    int32_t GetLevel() const { return Level; }
    EPlayerClass GetPlayerClass() const { return PlayerClass; }
    CLP_InventoryComponent* GetInventory() { return InventoryComponent.get(); }
    
    // Setters
    void SetName(const std::string& NewName) { Name = NewName; }
    void SetLevel(int32_t NewLevel) { Level = NewLevel; }
    void SetPlayerClass(EPlayerClass NewClass) { PlayerClass = NewClass; }
    
private:
    std::string Name;
    std::unique_ptr<CLP_InventoryComponent> InventoryComponent;
    int32_t Level;
    EPlayerClass PlayerClass;
};
/*-------------------------------------------------------------------------*/
