//Deck.h

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
	Card* cards;
	int size;
	int topCard;
public:
	Deck();
	~Deck();

	void shuffle();
	Card drawCard();

	int getTopCard();
	int getSize();
	Card* getCards();

	void setSize(int);
	void setTopCard(int);

	void loadCards(Card[], int);
	void reset();
	void buildDeck();
};

#endif