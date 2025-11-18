// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include "CLP_CharacterBase.h"
#include "../Core/Types/CLP_EnumTypes.h"

/*-------------------------------------------------------------------------*/
/*  Enemy Class                                                           */
/*-------------------------------------------------------------------------*/
class CLP_Enemy : public CLP_CharacterBase
{
public:
    CLP_Enemy();
    CLP_Enemy(EEnemyType Type);
    virtual ~CLP_Enemy();
    
    // Getters
    EEnemyType GetEnemyType() const { return EnemyType; }
    
    // Setters
    void SetEnemyType(EEnemyType NewType);
    
private:
    EEnemyType EnemyType;
    
    // Helper function to set stats based on enemy type
    void InitializeEnemyStats();
};
/*-------------------------------------------------------------------------*/
