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

using namespace std;

#pragma region User Libraries
//User Libraries//struct for a single card
#include "Card.h"
#include "Player.h"

//struct for a deck of cards
struct Deck
{
    Card* cards;
    int size;
    int topCard;
};

//struct used for saving and loading game data
struct SaveData
{
    char name[20];

    Card playerHand[52];
    int playerHandSize;
    int playerTotal;

    Card dealerHand[52];
    int dealerHandSize;
    int dealerTotal;

    Card deckCards[52];
    int topCard;
    int size;
};

enum MenuOptions
{
    START = 1,
    LOAD = 2,
    EXIT = 3
};

#pragma endregion

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

#pragma region Function Prototypes
                // card/deck functions
Deck initializeDeck();
void shuffleDeck(Deck&);

//player/ hand functions
void getPlayer(Player&);
void displayHand(Player&);
void displayHand(Character&);
void hit(Deck&, Player&);
void hit(Deck&, Character&);

//gameplay functions
void startingDraw(Deck&, Player&, Character&);
void dealerTurn(Deck&, Character&, const int);
void gameLoop(Deck&, Player&, Character&, const int, bool&);
bool replay(Deck&, Player&, Character&, bool&);
void checkWinner(Player&, Character&, const int);
void dealCard(Deck&, Character&);

//menu system
void menu();
void menuSelection(Deck&, Player&, Character&, const int, bool&);

//save / load system
void saveGame(Deck&, Player&, Character&);
void loadGame(Deck&, Player&, Character&);
#pragma endregion

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function
    Deck deck;
    Player player;
    Character dealer;
    const int BLACKJACK = 21;

    //Initialize all known variables
    bool quit = false;

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    deck = initializeDeck();
    menuSelection(deck, player, dealer, BLACKJACK, quit);

    //gameLoop(deck, player, dealer, BLACKJACK);
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    player.Character::~Character();
    dealer.Character::~Character();
    delete[] deck.cards;

    return 0;
}

//Function Implementations

//Creates and returns a 52 deck of cards
Deck initializeDeck()
{
    Deck d;

    //array for values, ranks, and suit that a card will have
    string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    string suits[] = { "Hearts", "Spades", "Clubs", "Diamonds" };
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

    //allocates memory for deck
    d.cards = new Card[52];
    d.size = 52;
    d.topCard = 0;

    //tracks position of card from 0 to 51
    int indx = 0;

    const int NUM_SUITS = 4;
    const int NUM_RANKS = 13;

    //Assigns a rank, suit, and value to a card
    for (int i = 0; i < NUM_SUITS; i++)
    {
        for (int j = 0; j < NUM_RANKS; j++)
        {
            strcpy_s(d.cards[indx].suit, suits[i].c_str());
            strcpy_s(d.cards[indx].rank, ranks[j].c_str());
            d.cards[indx].value = values[j];

            indx++;
        }
    }

    return d;
}

//Shuffles the original deck using Fisher yates algorithm
void shuffleDeck(Deck& d)
{
    Card temp;
    int r;
    //finds random index then swaps 
    for (int i = d.size - 1; i > 0; i--)
    {
        r = rand() % (i + 1);

        temp = d.cards[i];
        d.cards[i] = d.cards[r];
        d.cards[r] = temp;
    }
}

//starts game by dealing 2 cards to player and dealer
void startingDraw(Deck& d, Player& player, Character& dealer)
{
    const int START_DEAL = 2;

    shuffleDeck(d);

    for (int i = 0; i < START_DEAL; i++)
    {
        dealCard(d, player);
        dealCard(d, dealer);
    }
}

//Displays the players hand
void displayHand(Player& p)
{
    for (int i = 0; i < p.getHandSize(); i++)
    {
        cout << p.getHand()[i].rank << " of " << p.getHand()[i].suit << endl;
    }
    cout << "Total: " << p.getTotal() << endl;
    cout << "Money: $" << p.getChips() << endl;
}

//Displays the dealers hand
void displayHand(Character& p)
{
    for (int i = 0; i < p.getHandSize(); i++)
    {
        cout << p.getHand()[i].rank << " of " << p.getHand()[i].suit << endl;
    }
    cout << "Total: " << p.getTotal() << endl;
}

//draws card for player and displays hand after getting new card
void hit(Deck& d, Player& p)
{
    dealCard(d, p);
    displayHand(p);
}

//draws card for dealer and displays hand after getting new card
void hit(Deck& d, Character& p)
{
    dealCard(d, p);
    displayHand(p);
}

//determines winner of round
void checkWinner(Player& player, Character& dealer, const int BLACKJACK)
{
    cout << endl;
    if (player.getTotal() == BLACKJACK && dealer.getTotal() == BLACKJACK)
    {
        cout << "DRAW." << endl;
    }
    else if (player.getTotal() == BLACKJACK)
    {
        cout << "You win!" << endl;
        player.winBet();
    }
    else if (dealer.getTotal() > BLACKJACK)
    {
        cout << "Dealer BUST. You win!" << endl;
        player.winBet();
    }
    else if (dealer.getTotal() == BLACKJACK)
    {
        cout << "Dealer hit 21. You lose." << endl;
        player.loseBet();
    }
    else if (player.getTotal() > dealer.getTotal())
    {
        cout << "You win!" << endl;
        player.winBet();
    }
    else if (dealer.getTotal() > player.getTotal())
    {
        cout << "You Lose!" << endl;
        player.loseBet();
    }
    else if (player.getTotal() == dealer.getTotal())
    {
        cout << "DRAW!" << endl;
    }
}

//dealer logic
void dealerTurn(Deck& d, Character& dealer, const int BLACKJACK)
{
    const int DEALER_HIT = 16;

    cout << endl;
    cout << "Dealers cards" << endl;
    displayHand(dealer);

    //dealer already has blackjack
    if (dealer.getTotal() == BLACKJACK && dealer.getHandSize() == 2)
    {
        return;
    }
    else
    {
        //dealer keeps hitting until above 16
        while (dealer.getTotal() <= DEALER_HIT)
        {
            cout << endl;
            cout << "Dealer hits" << endl << endl;
            cout << "Dealers cards" << endl;
            hit(d, dealer);
        }
        cout << endl;
        cout << "Dealer stands." << endl;
    }
}

//Controls hit/stand, dealer logic, and win conditions
void gameLoop(Deck& d, Player& player, Character& dealer, const int BLACKJACK, bool& quit, bool& loaded)
{
    int user;
    int betAmt;
    bool playAgain;
    bool turn;

    do
    {
        //start new game or continue loaded game
        if (!loaded)
        {
            delete[] d.cards;
            d = initializeDeck();
            startingDraw(d, player, dealer);
        }
        else
        {
            loaded = false;
        }

        cout << player.getName() << " hand:" << endl;
        displayHand(player);

        //instant blackjack check
        if (player.getTotal() == BLACKJACK && player.getHandSize() == 2)
        {
            cout << endl;
            cout << "BLACK JACK!" << endl;
            dealerTurn(d, dealer, BLACKJACK);
            if (player.getTotal() == BLACKJACK && player.getHandSize() == 2 && dealer.getTotal() == BLACKJACK && dealer.getHandSize() == 2)
            {
                cout << "Dealer Black JACK!" << endl;
                cout << endl;
                cout << "Draw!" << endl;
            }
            else
            {
                cout << "You win!" << endl;
                player.winBet();
            }
        }
        else
        {
            turn = true;

            //player decision loop hit, stand, or save
            while (turn)
            {
                cout << endl;
                cout << "Do you want to HIT or STAND?" << endl;
                cout << "HIT = 1    STAND = 2   BET = 3    SAVE GAME = 4" << endl;

                cin >> user;

                switch (user)
                {
                case 1:
                    cout << endl;
                    cout << player.getName() << " hand:" << endl;
                    hit(d, player);
                    if (player.getTotal() > BLACKJACK)
                    {
                        cout << endl;
                        cout << "BUST!" << endl;
                        player.loseBet();
                        turn = false;
                    }
                    break;
                case 2:
                    turn = false;
                    break;
                case 3:
                    cout << "How much do you want to bet?" << endl;
                    cin >> betAmt;
                    player.setBet(betAmt);
                    player.setChips(betAmt);
                    break;
                case 4:
                    saveGame(d, player, dealer);
                    displayHand(player);
                    break;
                default:
                    cout << "Invalid option. Try again" << endl;
                    break;
                }
            }

            //dealer plays after player stands
            if (player.getTotal() <= BLACKJACK)
            {
                if (dealer.getTotal() == BLACKJACK && dealer.getHandSize() == 2)
                {
                    cout << "Dealer BLACK JACK! You lose!" << endl;
                    break;
                }
                else
                {
                    dealerTurn(d, dealer, BLACKJACK);
                    checkWinner(player, dealer, BLACKJACK);
                }
            }
        }

        playAgain = replay(d, player, dealer, quit);

    } while (playAgain);
}

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
    cout << "3. Exit" << endl;
}

//handles menu selection logic
void menuSelection(Deck& d, Player& player, Character& dealer, const int BLACKJACK, bool& quit)
{
    int user;
    bool running = true;
    bool loaded = false;

    while (running && !quit)
    {
        menu();
        cin >> user;

        switch (user)
        {
        case START:
            getPlayer(player);
            gameLoop(d, player, dealer, BLACKJACK, quit, loaded);
            break;
        case LOAD:

            loadGame(d, player, dealer);
            loaded = true;
            gameLoop(d, player, dealer, BLACKJACK, quit, loaded);
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

//replay
bool replay(Deck& d, Player& player, Character& dealer, bool& quit)
{
    char choice;

    cout << endl;
    cout << "Play again? (y/n): ";
    cin >> choice;
    cout << endl;

    //restart game
    if (choice == 'y' || choice == 'Y')
    {
        player.reset();
        dealer.reset();
        return true;
    }

    //fully exit game
    if (choice == 'n' || choice == 'N')
    {
        quit = true;
        return false;
    }
    return false;
}

//save game data
void saveGame(Deck& d, Player& player, Character& dealer)
{
    //open binary output file
    ofstream out("save.dat", ios::binary);

    SaveData data;

    //copy player data
    strcpy_s(data.name, player.getName());

    data.playerHandSize = player.getHandSize();
    data.playerTotal = player.getTotal();

    for (int i = 0; i < player.getHandSize(); i++)
    {
        data.playerHand[i] = player.getHand()[i];
    }

    //copy dealer data
    data.dealerHandSize = dealer.getHandSize();
    data.dealerTotal = dealer.getTotal();

    for (int i = 0; i < dealer.getHandSize(); i++)
    {
        data.dealerHand[i] = dealer.getHand()[i];
    }

    //copy deck data
    data.topCard = d.topCard;
    data.size = d.size;

    for (int i = 0; i < d.size; i++)
    {
        data.deckCards[i] = d.cards[i];
    }

    out.write(reinterpret_cast<char*>(&data), sizeof(SaveData));
    out.close();

    cout << "Game saved!" << endl << endl;
}

//load game data
void loadGame(Deck& d, Player& player, Character& dealer)
{
    //open binary file
    ifstream saveData("save.dat", ios::binary);

    if (!saveData)
    {
        cout << "No save file found." << endl;
        return;
    }

    SaveData data;

    //read structure from file
    saveData.read(reinterpret_cast<char*>(&data), sizeof(SaveData));

    //load save data for player
    player.reset();

    player.setName(data.name);

    player.setHandSize(data.playerHandSize);
    player.setTotal(data.playerTotal);

    //copies cards
    player.setHand(data.playerHand);

    //load save data for dealer
    dealer.reset();

    dealer.setHandSize(data.dealerHandSize);
    dealer.setTotal(data.dealerTotal);

    //copy dealer card
    dealer.setHand(data.dealerHand);

    //load deck
    delete[] d.cards;

    d.cards = new Card[data.size];
    d.size = data.size;
    d.topCard = data.topCard;

    //copy deck cards
    for (int i = 0; i < d.size; i++)
    {
        d.cards[i] = data.deckCards[i];
    }

    saveData.close();

    cout << "Game loaded!" << endl << endl;
}

void dealCard(Deck& d, Character& recipient)
{
    recipient.addCard(d.cards[d.topCard]);

    d.topCard++;
}
