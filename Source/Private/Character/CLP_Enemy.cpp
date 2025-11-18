// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Character/CLP_Enemy.h"

/*-------------------------------------------------------------------------*/
/*  Constructor/Destructor                                                */
/*-------------------------------------------------------------------------*/
CLP_Enemy::CLP_Enemy()
    : CLP_CharacterBase()
    , EnemyType(EEnemyType::None)
{
    InitializeEnemyStats();
}

CLP_Enemy::CLP_Enemy(EEnemyType Type)
    : CLP_CharacterBase()
    , EnemyType(Type)
{
    InitializeEnemyStats();
}

CLP_Enemy::~CLP_Enemy()
{
}

/*-------------------------------------------------------------------------*/
/*  Enemy Type Management                                                 */
/*-------------------------------------------------------------------------*/
void CLP_Enemy::SetEnemyType(EEnemyType NewType)
{
    EnemyType = NewType;
    InitializeEnemyStats();
}

void CLP_Enemy::InitializeEnemyStats()
{
    switch (EnemyType)
    {
        case EEnemyType::Goblin:
            Health = 50.0f;
            Attack = 5.0f;
            break;
            
        case EEnemyType::Skeleton:
            Health = 75.0f;
            Attack = 10.0f;
            break;
            
        case EEnemyType::Giant:
            Health = 200.0f;
            Attack = 25.0f;
            break;
            
        case EEnemyType::None:
        default:
            Health = 100.0f;
            Attack = 10.0f;
            break;
    }
}
/*-------------------------------------------------------------------------*/
