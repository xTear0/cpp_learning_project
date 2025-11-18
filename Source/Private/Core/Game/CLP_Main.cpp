// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Core/Game/CLP_Game.h"

/*-------------------------------------------------------------------------*/
/*  Main Entry Point                                                      */
/*-------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{
    // Print Hello World first as requested
    std::cout << "Hello World!" << std::endl;
    std::cout << std::endl;
    
    // Create game instance
    CLP_Game game;
    
    // Initialize the game
    if (game.Initialize())
    {
        // Run the main game loop
        game.Run();
    }
    
    // Clean up
    game.Shutdown();
    
    return 0;
}
/*-------------------------------------------------------------------------*/
