//Character.h

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Card.h"

class Character
{
private:
    Card* hand;
    int handSize;
    int total;
public:
    //constructor destructor
    Character();
    virtual ~Character();
    
    //getters
    Card* getHand();
    int getHandSize();
    int getTotal();

    //member functions
    void addCard(Card);
    void reset();

};
#endif