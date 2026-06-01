//Character.cpp

#include "Character.h"
#include <iostream>

using namespace std;

//Constructor
Character::Character()
{
	hand = nullptr;
	handSize = 0;
	total = 0;
}

Character::Character(const Character& other)
{
    handSize = other.handSize;
    total = other.total;

    if (other.hand != nullptr)
    {
        hand = new Card[handSize];

        for (int i = 0; i < handSize; i++)
        {
            hand[i] = other.hand[i];
        }
    }

    else
    {
        hand = nullptr;
    }
}

Character::~Character()
{
	delete[] hand;
}

//getters
Card* Character::getHand()
{
	return hand;
}

int Character::getHandSize()
{
	return handSize;
}

int Character::getTotal()
{
	return total;
}

//setters
void Character::setHand(Card* c)
{
    delete[] hand;

    hand = new Card[handSize];

    for (int i = 0; i < handSize; i++)
    {
        hand[i] = c[i];
    }
}

void Character::setHandSize(int t)
{
    handSize = t;
}

void Character::setTotal(int t)
{
    total = t;
}

//character game functions
void Character::addCard(Card c)
{
    //dynamically increases size of recipients deck
    Card* newHand = new Card[handSize + 1];

    //copies old hand into new
    for (int i = 0; i < handSize; i++)
    {
        newHand[i] = hand[i];
    }

    //add new card
    newHand[handSize] = c;

    //delete old hand
    delete[] hand;

    //Updates characters hand, total, and hand size
    hand = newHand;
    handSize++;

    //recalculate total for ace
    total = 0;
    int aceCount = 0;

    for (int i = 0; i < handSize; i++)
    {
        total += hand[i].value;

        if (strcmp(hand[i].rank, "Ace") == 0)
        {
            aceCount++;
        }
    }

    //Change ace value from 1 to 11 when possible
    while (aceCount > 0 && total + 10 <= 21)
    {
        total += 10;
        aceCount--;
    }
}

void Character::reset()
{
    delete[] hand;

    hand = nullptr;
    handSize = 0;
    total = 0;
}

void Character::showInfo()
{
    cout << "Dealer Total: " << total << endl;
}

//overloaded operators
bool Character::operator==(const Character& other)
{
    return total == other.total;
}

bool Character::operator>(const Character& other)
{
    return total > other.total;
}