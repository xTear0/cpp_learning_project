// Copyright xTear Studios
/*-------------------------------------------------------------------------*/
#include "Core/Game/CLP_Game.h"
#include "Inventory/ItemComponent/Items/CLP_Items.h"
#include <iostream>

using namespace std;


/*-------------------------------------------------------------------------*/
/*  Constructor/Destructor                                                */
/*-------------------------------------------------------------------------*/
CLP_Game::CLP_Game()
    : bIsRunning(false)
{
    Hero = new CLP_Hero();
}

CLP_Game::~CLP_Game()
{
    delete Hero;
}

/*-------------------------------------------------------------------------*/
/*  Initialize                                                            */
/*-------------------------------------------------------------------------*/
bool CLP_Game::Initialize()
{
    cout << "==================================" << '\n';
    cout << "   C++ Learning Project (CLP)     " << '\n';
    cout << "==================================" << '\n';
    cout << '\n';
    
    bIsRunning = true;
    // Ask for a username and create a player class.
    string username;
    cout << "> Enter a character username: ";
    cout << '\n';
    getline(cin, username);
    Hero->SetName(username);
    
    cout << '\n';
    cout << "Welcome, " << username << ", to the game world of C++ programming!" << '\n';
    cout << "In this game, you can run commands, move around, and explore!" << '\n';
    cout << "For hints and commands, run 'help' and to end the program type 'quit'." << '\n';
    cout << '\n';
    
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
    }
}

/*-------------------------------------------------------------------------*/
/*  Process Input                                                          */
/*-------------------------------------------------------------------------*/
void CLP_Game::ProcessInput()
{
    string input;
    cout << "> Enter command (type 'help' for commands, 'quit' to exit): ";
    getline(cin, input);
    
    if (input == "quit" || input == "exit")
    {
        bIsRunning = false;
    }
    else if (input == "help")
    {
        PrintHelpMenu();
    }
    else if (input == "inventory")
    {
        Hero->GetInventory()->ListItems();
    }
    else if (input == "give")
    {
        string item;
        int amount;
        cout << "> Enter item: ";
        cin >> input;
        cout << "> Enter amount: ";
        cin >> amount;
        
        cin.ignore(); // Clear the newline from the buffer
        cout << "Requested item: " << input << " (x" << amount << ")" << '\n';
        
        if (input == "RedPotion")
        {
            CLP_ItemData RequestedItem = ItemDatabase::CreateRedPotion();
            Hero->GetInventory()->AddItem(RequestedItem.ID, RequestedItem.Name, RequestedItem.Description, amount);
        }
        else if (input == "BlueberryMuffin")
        {
            CLP_ItemData RequestedItem = ItemDatabase::CreateBlueberryMuffin();
            Hero->GetInventory()->AddItem(RequestedItem.ID, RequestedItem.Name, RequestedItem.Description, amount);
        }
        else if (input == "SwordOfLegends")
        {
            CLP_ItemData RequestedItem = ItemDatabase::CreateSwordOfLegends();
            Hero->GetInventory()->AddItem(RequestedItem.ID, RequestedItem.Name, RequestedItem.Description, amount);
        }
        else
        {
            cout << "Unknown item: " << input << '\n';
        }
    }
    else if (!input.empty())
    {
        cout << "Unknown command: " << input << '\n';
    }
}

void CLP_Game::PrintHelpMenu()
{
    cout << "\nAvailable commands:" << '\n';
    cout << "  help                - Prints this menu."                << '\n';
    //cout << "  move 'direction'    - Moves your character (n,s,e,w)."  << '\n';
    //cout << "  attack 'item'       - Attacks nearby enemy with item."  << '\n';
    cout << "  inventory           - List items in your inventory."     << '\n';
    cout << "  give                - Gives you a specified item."  << '\n';
    cout << "  quit                - Exit out of the game thread."     << '\n';
    cout << '\n';
}

/*-------------------------------------------------------------------------*/
/*  Update                                                                 */
/*-------------------------------------------------------------------------*/
void CLP_Game::Update()
{
    // Game logic updates will go here
}

/*-------------------------------------------------------------------------*/
/*  Shutdown                                                               */
/*-------------------------------------------------------------------------*/
void CLP_Game::Shutdown()
{
    cout << "\nShutting down game..." << '\n';
    cout << "Goodbye!" << '\n';
}
/*-------------------------------------------------------------------------*/