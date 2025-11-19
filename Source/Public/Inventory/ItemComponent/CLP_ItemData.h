// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include <string>

using namespace std;

/*-------------------------------------------------------------------------*/
/*  Item Data - Simple struct for storing item information                */
/*-------------------------------------------------------------------------*/
struct CLP_ItemData
{
    int ID;
    string Name;
    string Description;
    int StackCount;
    
    // Constructor
    CLP_ItemData()
        : ID(0)
        , Name("Empty")
        , Description("Empty")
        , StackCount(0)
    {}
    
    CLP_ItemData(int InID, const string& InName, const string& InDescription, int InStackCount = 1)
        : ID(InID)
        , Name(InName)
        , Description(InDescription)
        , StackCount(InStackCount)
    {}
    
    // Helper functions
    bool IsValid() const { return ID > 0 && StackCount > 0 && !Name.empty(); }
};
/*-------------------------------------------------------------------------*/