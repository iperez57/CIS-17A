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
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
Deck initializeDeck();
void shuffleDeck(Deck&);
void dealCard(Deck&, Player&);
void startGame(Deck&, Player&, Player&);
void displayHand(Player&);
void hit(Deck&, Player&);
void checkWinner(Player&, Player&);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(time(0));
    //Declare all variables for this function
    Deck deck;
    Player player;
    Player dealer;

    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    deck = initializeDeck();
    shuffleDeck(deck);
    startGame(deck, player, dealer);
    displayHand(player);
    hit(deck, player);
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
void startGame(Deck& d, Player& player, Player& dealer)
{
    const int START_DEAL = 2;

    for (int i = 0; i < START_DEAL; i++)
    {
        dealCard(d, player);
        dealCard(d, dealer);
    }
}

//Displays the players hand
void displayHand(Player& p)
{
    cout << "Your hand: " << endl;
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
void checkWinner(Player& player, Player& dealer)
{
    const int BLACKJACK = 21;

    if (player.total == BLACKJACK && dealer.total == BLACKJACK)
    {
        cout << "DRAW." << endl;
    }
    else if (player.total == BLACKJACK)
    {
        cout << "BLACK JACK! You win!" << endl;
    }
    else if (player.total > BLACKJACK)
    {
        cout << "BUST." << endl;
    }
    else if (dealer.total > BLACKJACK)
    {
        cout << "Dealer BUST. You win!" << endl;
    }
    else if (dealer.total == BLACKJACK)
    {
        cout << "Dealer has BLACK JACK. You lose." << endl;
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