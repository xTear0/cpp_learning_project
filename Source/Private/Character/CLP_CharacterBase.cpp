// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Character/CLP_CharacterBase.h"

/*-------------------------------------------------------------------------*/
/*  Constructor/Destructor                                                */
/*-------------------------------------------------------------------------*/
CLP_CharacterBase::CLP_CharacterBase()
    : Health(100.0f)
    , Attack(10.0f)
{
}

CLP_CharacterBase::~CLP_CharacterBase()
{
}

/*-------------------------------------------------------------------------*/
/*  Utility Functions                                                     */
/*-------------------------------------------------------------------------*/
void CLP_CharacterBase::TakeDamage(float Damage)
{
    Health -= Damage;
    if (Health < 0.0f)
    {
        Health = 0.0f;
    }
}

bool CLP_CharacterBase::IsAlive() const
{
    return Health > 0.0f;
}
/*-------------------------------------------------------------------------*/
