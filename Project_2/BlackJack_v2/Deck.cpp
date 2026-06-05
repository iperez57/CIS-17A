//Deck.cpp

#include "Deck.h"
#include <iostream>

using namespace std;

//Creates and returns a 52 deck of cards
Deck::Deck()
{
    cards = nullptr;
    buildDeck();
}

Deck::~Deck()
{
    delete[] cards;
}

//Shuffles the original deck using Fisher yates algorithm
void Deck::shuffle()
{
    topCard = 0;
    Card temp;
    int r;
    //finds random index then swaps 
    for (int i = size - 1; i > 0; i--)
    {
        r = rand() % (i + 1);

        temp = cards[i];
        cards[i] = cards[r];
        cards[r] = temp;
    }
}

Card Deck::drawCard()
{
    if (topCard >= size)
    {
        shuffle();
        topCard = 0;
    }
    return cards[topCard++];
}

int Deck::getTopCard()
{
    return topCard;
}

int Deck::getSize()
{
    return size;
}

Card* Deck::getCards()
{
    return cards;
}

void Deck::setSize(int s)
{
    size = s;
}

void Deck::setTopCard(int t)
{
    topCard = t;
}

void Deck::loadCards(Card source[], int sz)
{
    delete[] cards;

    cards = new Card[sz];

    for (int i = 0; i < sz; i++)
    {
        cards[i] = source[i];
    }

    size = sz;
    topCard = 0;
}

void Deck::reset()
{
    delete[] cards;
    buildDeck();
}

void Deck::buildDeck()
{
    string ranks[] = { "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
    string suits[] = { "Hearts","Spades","Clubs","Diamonds" };
    int values[] = { 1,2,3,4,5,6,7,8,9,10,10,10,10 };

    cards = new Card[52];
    size = 52;
    topCard = 0;

    int indx = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            strcpy_s(cards[indx].suit, suits[i].c_str());
            strcpy_s(cards[indx].rank, ranks[j].c_str());
            cards[indx].value = values[j];
            indx++;
        }
    }
}