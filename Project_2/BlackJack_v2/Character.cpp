//Character.cpp

#include "Character.h"

using namespace std;

//Constructor
Character::Character()
{
	hand = nullptr;
	handSize = 0;
	total = 0;
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
    total += c.value;
    handSize++;
}

void Character::reset()
{
    delete[] hand;

    hand = nullptr;
    handSize = 0;
    total = 0;
}