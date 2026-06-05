/*
 * File:   BlackJack_v2.cpp
 * Author: Isaac Perez
 * Created: 05/25/2026
 * Purpose:  Use content from chapters 13-16
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <cstring>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

#pragma region User Libraries
//User Libraries
#include "Card.h"
#include "Player.h"
#include "Stats.h"
#include "Dealer.h"
#include "Deck.h"
#include "GameEngine.h"

template <class T>
void dealCard(Deck& d, T& recipient)
{
    recipient.addCard(d.drawCard());

}

enum MenuOptions
{
    START = 1,
    LOAD = 2,
    STATS = 3,
    EXIT = 4
};

#pragma endregion

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

#pragma region Function Prototypes
//player/ hand functions
void getPlayer(Player&);

//menu system
void menu();
void menuSelection(Deck&, Player&, Dealer&, Stats&, const int, bool&);

#pragma endregion

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function
    Deck deck;
    Player player;
    Dealer dealer;
    Stats stats;
    const int BLACKJACK = 21;

    //Initialize all known variables
    bool quit = false;

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    menuSelection(deck, player, dealer, stats, BLACKJACK, quit);

    //gameLoop(deck, player, dealer, BLACKJACK);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations

//ask for player info
void getPlayer(Player& player)
{
    char temp[20];

    cout << "Create Username: ";
    cin.ignore();
    cin.getline(temp, 20);
    cout << endl;

    player.setName(temp);
}

//display menu
void menu()
{
    cout << "Black Jack" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. View Game Stats" << endl;
    cout << "4. Exit" << endl;
}

//handles menu selection logic
void menuSelection(Deck& d, Player& player, Dealer& dealer, Stats& stats, const int BLACKJACK, bool& quit)
{
    GameEngine game;
    int user;
    bool running = true;
    bool loaded = false;
    int decks;

    while (running && !quit)
    {
        menu();
        cin >> user;
        cout << endl;

        switch (user)
        {
        case START:
            getPlayer(player);
            cout << "How many decks? (1-3): ";
            cin >> decks;
            d.buildDeck(decks);
            game.gameLoop(d, player, dealer, BLACKJACK, quit, loaded);
            break;
        case LOAD:
            game.loadGame(d, player, dealer);
            loaded = true;
            game.gameLoop(d, player, dealer, BLACKJACK, quit, loaded);
            break;
        case STATS:
            stats.displayStats(player);
            break;
        case EXIT:
            cout << "Exiting game ..." << endl;
            running = false;
            quit = true;
            break;
        default:
            cout << "Try again. That wasn't an option!" << endl;
            break;
        }
    }
    cout << "Thank you for playing!" << endl;
}