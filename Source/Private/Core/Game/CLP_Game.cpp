// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Core/Game/CLP_Game.h"

#include <iostream>

/*-------------------------------------------------------------------------*/
/*  Constructor/Destructor                                                */
/*-------------------------------------------------------------------------*/
CLP_Game::CLP_Game()
    : bIsRunning(false)
{
}

CLP_Game::~CLP_Game()
{
}

/*-------------------------------------------------------------------------*/
/*  Initialize                                                            */
/*-------------------------------------------------------------------------*/
bool CLP_Game::Initialize()
{
    std::cout << "==================================" << std::endl;
    std::cout << "   C++ Learning Project (CLP)    " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;
    
    bIsRunning = true;
    return true;
}

/*-------------------------------------------------------------------------*/
/*  Main Game Loop                                                        */
/*-------------------------------------------------------------------------*/
void CLP_Game::Run()
{
    while (bIsRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

/*-------------------------------------------------------------------------*/
/*  Process Input                                                         */
/*-------------------------------------------------------------------------*/
void CLP_Game::ProcessInput()
{
    std::string input;
    std::cout << "> Enter command (type 'help' for commands, 'quit' to exit): ";
    std::getline(std::cin, input);
    
    if (input == "quit" || input == "exit")
    {
        bIsRunning = false;
    }
    else if (input == "help")
    {
        std::cout << "\nAvailable commands:" << std::endl;
        std::cout << "  help  - Show this help menu" << std::endl;
        std::cout << "  quit  - Exit the game" << std::endl;
        std::cout << std::endl;
    }
    else if (!input.empty())
    {
        std::cout << "Unknown command: " << input << std::endl;
    }
}

/*-------------------------------------------------------------------------*/
/*  Update                                                                */
/*-------------------------------------------------------------------------*/
void CLP_Game::Update()
{
    // Game logic updates will go here
}

/*-------------------------------------------------------------------------*/
/*  Render                                                                */
/*-------------------------------------------------------------------------*/
void CLP_Game::Render()
{
    // Display updates will go here
}

/*-------------------------------------------------------------------------*/
/*  Shutdown                                                              */
/*-------------------------------------------------------------------------*/
void CLP_Game::Shutdown()
{
    std::cout << "\nShutting down game..." << std::endl;
    std::cout << "Goodbye!" << std::endl;
}
/*-------------------------------------------------------------------------*/
