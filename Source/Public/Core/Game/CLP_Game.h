// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Character/CLP_Hero.h"


/*-------------------------------------------------------------------------*/
/*  Main Game Class                                                       */
/*-------------------------------------------------------------------------*/
class CLP_Game
{
public:
    CLP_Game();
    ~CLP_Game();
    
    // Initialize the game
    bool Initialize();
    
    // Main game loop
    void Run();
    
    // Cleanup
    static void Shutdown();
    
private:
    bool bIsRunning;
    CLP_Hero* Hero;
    
    // Process player input
    void ProcessInput();

    // Prints help menu
    static void PrintHelpMenu();
    
    // Update game state
    static void Update();
    
    // Display current state
    void Render();
};
/*-------------------------------------------------------------------------*/
