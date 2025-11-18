// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

/*-------------------------------------------------------------------------*/
/*  Character Base                                                        */
/*-------------------------------------------------------------------------*/
#pragma region CLP_CharacterBase.h_Class

class CLP_CharacterBase
{
public:
    CLP_CharacterBase();
    virtual ~CLP_CharacterBase();
    
    // Getters
    float GetHealth() const { return Health; }
    float GetAttack() const { return Attack; }
    
    // Setters
    void SetHealth(float NewHealth) { Health = NewHealth; }
    void SetAttack(float NewAttack) { Attack = NewAttack; }
    
    // Utility functions
    virtual void TakeDamage(float Damage);
    virtual bool IsAlive() const;
    
protected:
    float Health;
    float Attack;
};

#pragma endregion
/*-------------------------------------------------------------------------*/
