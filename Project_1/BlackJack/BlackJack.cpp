/*
 * File:   BlackJack
 * Author: Isaac Perez
 * Created: 04/29/2026
 * Purpose:  Use content from chapters 9-12
 */

 //System Libraries
#include <iostream>  //I/O Library

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
    string name;
    Card* hand;
    int handSize;
    int total;
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
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here

    //Declare all variables for this function
    Deck deck;
    Player player;
    Player dealer;

    //Initialize all known variables

    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    //Display the Inputs/Outputs
    deck = initializeDeck();
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right

    return 0;
}

//Function Implementations
Deck initializeDeck()
{
    Deck d;

    string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    string suits[] = { "Hearts", "Spades", "Clubs", "Diamonds" };
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

    d.cards = new Card[52];
    d.size = 52;
    d.topCard = 0;

    int indx = 0;

    const int NUM_SUITS = 4;
    const int NUM_RANKS = 13;

    //Initializes deck
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