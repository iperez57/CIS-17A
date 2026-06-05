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

//template
template <class T>
void displayHand(T& obj)
{
    for (int i = 0; i < obj.getHandSize(); i++)
    {
        cout << obj.getHand()[i].rank << " of " << obj.getHand()[i].suit << endl;
    }
    obj.showInfo();
}

template <class T>
void dealCard(Deck& d, T& recipient)
{
    recipient.addCard(d.drawCard());

}
//struct used for saving and loading game data
struct SaveData
{
    char name[20];

    //player bets
    int chips;
    int bet;

    Card playerHand[52];
    int playerHandSize;
    int playerTotal;

    Card dealerHand[52];
    int dealerHandSize;
    int dealerTotal;

    Card deckCards[52];
    int topCard;
    int size;

    //game stats
    int wins;
    int loss;
    int ties;
    int gamesPlayed;
};

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
void hit(Deck&, Player&);
void hit(Deck&, Dealer&);

//gameplay functions
void startingDraw(Deck&, Player&, Dealer&);
void dealerTurn(Deck&, Dealer&, const int);
void gameLoop(Deck&, Player&, Dealer&, const int, bool&, bool&);
bool replay(Deck&, Player&, Dealer&, bool&);
void checkWinner(Player&, Dealer&, const int);
void displayGameBoard(Player&, Dealer&);

//menu system
void menu();
void menuSelection(Deck&, Player&, Dealer&, Stats&, const int, bool&);

//save / load system
void saveGame(Deck&, Player&, Dealer&);
void loadGame(Deck&, Player&, Dealer&);
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
//starts game by dealing 2 cards to player and dealer
void startingDraw(Deck& d, Player& player, Dealer& dealer)
{
    const int START_DEAL = 2;

    d.shuffle();

    for (int i = 0; i < START_DEAL; i++)
    {
        dealCard(d, player);
        dealCard(d, dealer);
    }
}

//draws card for player and displays hand after getting new card
void hit(Deck& d, Player& p)
{
    dealCard(d, p);
    displayHand(p);
}

//draws card for dealer and displays hand after getting new card
void hit(Deck& d, Dealer& p)
{
    dealCard(d, p);
    displayHand(p);
}

//determines winner of round
void checkWinner(Player& player, Dealer& dealer, const int BLACKJACK)
{
    cout << endl;
    if (player.getTotal() == BLACKJACK && dealer.getTotal() == BLACKJACK)
    {
        cout << "DRAW." << endl;
        player.tieBet();
        player.addTie();
    }
    else if (player.getTotal() == BLACKJACK)
    {
        cout << "You win!" << endl;
        player.winBet();
        player.addWin();
    }
    else if (dealer.getTotal() > BLACKJACK)
    {
        cout << "Dealer BUST. You win!" << endl;
        player.winBet();
        player.addWin();
    }
    else if (dealer.getTotal() == BLACKJACK)
    {
        cout << "Dealer hit 21. You lose." << endl;
        player.loseBet();
        player.addLoss();
    }
    else if (player > dealer)
    {
        cout << "You win!" << endl;
        player.winBet();
        player.addWin();
    }
    else if (dealer > player)
    {
        cout << "You Lose!" << endl;
        player.loseBet();
        player.addLoss();
    }
    else if (player == dealer)
    {
        cout << "DRAW!" << endl;
        player.tieBet();
        player.addTie();
    }
}

//dealer logic
void dealerTurn(Deck& d, Dealer& dealer, const int BLACKJACK)
{
    const int DEALER_HIT = 16;

    cout << endl << "Dealer shows hidden card" << endl;
    dealer.dealerCardMsg();
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
            //make the dealer look like it is thinking by waiting 2 seconds
            cout << endl;
            dealer.dealerThinkingMsg();
            this_thread::sleep_for(chrono::seconds(2));

            cout << endl;
            dealer.dealerHitMsg();
            dealer.dealerCardMsg();
            hit(d, dealer);
        }
        cout << endl;
        dealer.dealerStandMsg();
    }
}

//Controls hit/stand, dealer logic, and win conditions
void gameLoop(Deck& d, Player& player, Dealer& dealer, const int BLACKJACK, bool& quit, bool& loaded)
{
    int user;
    int betAmt;
    bool playAgain;
    bool turn;
    bool validB;

    do
    {
        //start new game or continue loaded game
        if (!loaded)
        {   
            d.reset();
            startingDraw(d, player, dealer);

            //demonstrate copy constructor
            Player backup(player);
        }
        else
        {
            loaded = false;
        }

        player.addGamePlayed();
        //ask player to enter a bet
        do
        {
            validB = false;
            try
            {
                cout << "Money: $" << player.getChips() << endl;
                cout << "How much do you want to place a bet? (min 10)" << endl;
                cin >> betAmt;
                cout << endl;

                player.setBet(betAmt);
                validB = true;
            }
            catch (Player::InvalidBet)
            {
                cout << "Minimum bet is $10" << endl;
            }
            catch (Player::NotEnoughChips)
            {
                cout << "You entered too much money." << endl;
            }

        } while (!validB);
        cout << player.getName() << " hand:" << endl;
        displayHand(player);
        
        cout << endl;
        dealer.dealerCardMsg();
        dealer.dealerHiddenHand();

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
                player.tieBet();
                player.addTie();
            }
            else
            {
                cout << "You win!" << endl;
                player.winBet();
                player.addWin();
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
                cout << "HIT = 1    STAND = 2   SAVE GAME = 3" << endl;

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
                        player.addLoss();
                        turn = false;
                    }
                    break;
                case 2:
                    turn = false;
                    break;
                case 3:
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
                    player.loseBet();
                    player.addLoss();
                    break;
                }
                else
                {
                    dealerTurn(d, dealer, BLACKJACK);
                    checkWinner(player, dealer, BLACKJACK);
                }
            }
        }

        //check if player is out of money
        try
        {
            player.validBet();

            playAgain = replay(d, player, dealer, quit);
        }
        catch (Player::NotEnoughChips)
        {
            cout << endl;
            cout << "You are out of money! Game Over!" << endl;
            cout << endl;
            playAgain = false;
        }

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
    cout << "3. View Game Stats" << endl;
    cout << "4. Exit" << endl;
}

//handles menu selection logic
void menuSelection(Deck& d, Player& player, Dealer& dealer, Stats& stats, const int BLACKJACK, bool& quit)
{
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
            gameLoop(d, player, dealer, BLACKJACK, quit, loaded);
            break;
        case LOAD:
            loadGame(d, player, dealer);
            loaded = true;
            gameLoop(d, player, dealer, BLACKJACK, quit, loaded);
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

//replay
bool replay(Deck& d, Player& player, Dealer& dealer, bool& quit)
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
        return false;
    }
    return false;
}

//save game data
void saveGame(Deck& d, Player& player, Dealer& dealer)
{
    //open binary output file
    ofstream out("save.dat", ios::binary);

    SaveData data;

    //copy player data
    strcpy_s(data.name, player.getName());

    data.chips = player.getChips();
    data.bet = player.getBet();
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
    data.topCard = d.getTopCard();
    data.size = d.getSize();

    for (int i = 0; i < d.getSize(); i++)
    {
        data.deckCards[i] = d.getCards()[i];
    }

    //copy game stats
    data.gamesPlayed = player.getGamesPlayed();
    data.wins = player.getGamesWon();
    data.loss = player.getGamesLoss();
    data.ties = player.getGamesTied();

    out.write(reinterpret_cast<char*>(&data), sizeof(SaveData));
    out.close();

    cout << "Game saved!" << endl << endl;
}

//load game data
void loadGame(Deck& d, Player& player, Dealer& dealer)
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

    player.setBet(data.bet);
    player.setChips(data.chips);
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
    d.loadCards(data.deckCards, data.size);
    d.setSize(data.size);
    d.setTopCard(data.topCard);

    //copy game stats
    player.setGamesPlayed(data.gamesPlayed);
    player.setGamesWon(data.wins);
    player.setGamesLoss(data.loss);
    player.setGamesTied(data.ties);

    saveData.close();

    cout << "Game loaded!" << endl << endl;
}