// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Core/Game/CLP_Game.h"

/*-------------------------------------------------------------------------*/
/*  Main Entry Point                                                      */
/*-------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{
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
