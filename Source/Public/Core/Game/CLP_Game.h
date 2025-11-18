// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#pragma once

#include <iostream>
#include <string>
#include <memory>

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
    void Shutdown();
    
private:
    bool bIsRunning;
    
    // Process player input
    void ProcessInput();
    
    // Update game state
    void Update();
    
    // Display current state
    void Render();
};
/*-------------------------------------------------------------------------*/
