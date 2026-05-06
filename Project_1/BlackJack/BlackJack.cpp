/*
 * File:   BlackJack
 * Author: Isaac Perez
 * Created: 04/29/2026
 * Purpose:  Use content from chapters 9-12
 */

 //System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>;

using namespace std;

//User Libraries
struct Card
{
    string rank;
    string suit;
    int value;
};

struct Player
{
    char name[20];
    Card* hand = nullptr;
    int handSize = 0;
    int total = 0;
};

struct Deck
{
    Card* cards;
    int size;
    int topCard;
};

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
};
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
Deck initializeDeck();
void shuffleDeck(Deck&);
void dealCard(Deck&, Player&);
void startingDraw(Deck&, Player&, Player&);
void displayHand(Player&);
void hit(Deck&, Player&);
void dealerTurn(Deck&, Player&, const int);
void gameLoop(Deck&, Player&, Player&, const int, bool&);
void getPlayer(Player&);
void menu();
void menuSelection(Deck&, Player&, Player&, const int, bool&);
void resetPlayer(Player&);
bool replay(Deck&, Player&, Player&, bool&);
void checkWinner(Player&, Player&, const int);
void saveGame(Deck&, Player&, Player&);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function
    Deck deck;
    Player player;
    Player dealer;
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

    delete[] player.hand;
    delete[] dealer.hand;
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
            d.cards[indx].suit = suits[i];
            d.cards[indx].rank = ranks[j];
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

//deals card to player
void dealCard(Deck& d, Player& recipient)
{
    //dynamically increases size of recipients deck
    Card* newHand = new Card[recipient.handSize + 1];

    for (int i = 0; i < recipient.handSize; i++)
    {
        newHand[i] = recipient.hand[i];
    }

    newHand[recipient.handSize] = d.cards[d.topCard];

    delete[] recipient.hand;

    //Updates players hand, total, and hand size
    recipient.hand = newHand;
    recipient.total += d.cards[d.topCard].value;
    recipient.handSize++;
    
    //changes the decks top card to next in line
    d.topCard++;
}

//starts game by dealing 2 cards to player and dealer
void startingDraw(Deck& d, Player& player, Player& dealer)
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
    for (int i = 0; i < p.handSize; i++)
    {
        cout << p.hand[i].rank << " of " << p.hand[i].suit << endl;
    }
    cout << "Total: " << p.total << endl;
}

//draws card for player and displays hand after getting new card
void hit(Deck& d, Player& p)
{
    dealCard(d, p);
    displayHand(p);
}

//check if a player is a winner
void checkWinner(Player& player, Player& dealer, const int BLACKJACK)
{
    cout << endl;
    if (player.total == BLACKJACK && dealer.total == BLACKJACK)
    {
        cout << "DRAW." << endl;
    }
    else if (player.total == BLACKJACK)
    {
        cout << "You win!" << endl;
    }
    else if (dealer.total > BLACKJACK)
    {
        cout << "Dealer BUST. You win!" << endl;
    }
    else if (dealer.total == BLACKJACK)
    {
        cout << "Dealer hit 21. You lose." << endl;
    }
    else if (player.total > dealer.total)
    {
        cout << "You win!" << endl;
    }
    else if (dealer.total > player.total)
    {
        cout << "You Lose!" << endl;
    }
    else if (player.total == dealer.total)
    {
        cout << "DRAW!" << endl;
    }
}

//dealer logic
void dealerTurn(Deck& d, Player& dealer, const int BLACKJACK)
{
    const int DEALER_HIT = 16;

    cout << endl;
    cout << "Dealers cards" << endl;
    displayHand(dealer);
    if (dealer.total == BLACKJACK && dealer.handSize == 2)
    {
        return;
    }
    else
    {
        while (dealer.total <= DEALER_HIT)
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

//Game Loop
void gameLoop(Deck& d, Player& player, Player& dealer, const int BLACKJACK, bool& quit)
{
    int user;
    bool playAgain;
    bool turn;

    do
    {
        delete[] d.cards;
    d = initializeDeck();
    startingDraw(d, player, dealer);

    cout << player.name <<" hand:" << endl;
    displayHand(player);
        if (player.total == BLACKJACK && player.handSize == 2)
        {
            cout << endl;
            cout << "BLACK JACK!" << endl;
            dealerTurn(d, dealer, BLACKJACK);
            if (player.total == BLACKJACK && player.handSize == 2 && dealer.total == BLACKJACK && dealer.handSize == 2)
            {
                cout << "Dealer Black JACK!" << endl;
                cout << endl;
                cout << "Draw!" << endl;
            }
            else
            {
                cout << "You win!" << endl;
            }
        }
        else
        {
            turn = true;
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
                    cout << player.name << " hand:" << endl;
                    hit(d, player);
                    if (player.total > BLACKJACK)
                    {
                        cout << endl;
                        cout << "BUST!" << endl;
                        turn = false;
                    }
                    break;
                case 2:
                    turn = false;
                    break;
                case 3:
                    saveGame(d, player, dealer);
                    break;
                default:
                    cout << "Invalid option. Try again" << endl;
                    break;
                }
            }

            if (player.total <= BLACKJACK)
            {
                if (dealer.total == BLACKJACK && dealer.handSize == 2)
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
    cout << "Create Username: ";
    cin.ignore();
    cin.getline(player.name, 20);
    cout << endl;
}

//display menu
void menu()
{
    cout << "Black Jack" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit" << endl;
}

//start of program
void menuSelection(Deck& d, Player& player, Player& dealer, const int BLACKJACK, bool& quit)
{
    int user;
    bool running = true;
    
    while (running && !quit)
    {
        menu();
        cin >> user;

        switch (user)
        {
        case 1:
            getPlayer(player);
            gameLoop(d, player, dealer, BLACKJACK, quit);
            break;
        case 2:
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
bool replay(Deck& d, Player& player, Player& dealer, bool& quit)
{
    char choice;

    cout << endl;
    cout << "Play again? (y/n): ";
    cin >> choice;
    cout << endl;

    if (choice == 'y' || choice == 'Y')
    {
        resetPlayer(player);
        resetPlayer(dealer);
        return true;
    }

    if (choice == 'n' || choice == 'N')
    {
        quit = true;
        return false;
    }
    return false;
}

//reset player
void resetPlayer(Player& p)
{
    delete[] p.hand;
    p.hand = nullptr;
    p.handSize = 0;
    p.total = 0;
}

void saveGame(Deck& d, Player& player, Player& dealer)
{
    ofstream out("save.dat", ios::binary);

    SaveData data;

    //copy player data
    strcpy_s(data.name, player.name);

    data.playerHandSize = player.handSize;
    data.playerTotal = player.total;

    for (int i = 0; i < player.handSize; i++)
    {
        data.playerHand[i] = player.hand[i];
    }

    //copy dealer data
    data.dealerHandSize = dealer.handSize;
    data.dealerTotal = dealer.total;

    for (int i = 0; i < dealer.handSize; i++)
    {
        data.dealerHand[i] = dealer.hand[i];
    }

    //copy deck data
    data.topCard = d.topCard;

    for (int i = 0; i < d.size; i++)
    {
        data.deckCards[i] = d.cards[i];
    }

    out.write((char*)&data, sizeof(data));
    out.close();

    cout << "Game saved!" << endl;


}
// display dealers 1 card
// check dealer bust / stand output