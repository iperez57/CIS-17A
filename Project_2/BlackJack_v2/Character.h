//Character.h

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Card.h"

class Character
{
protected:
    Card* hand;
    int handSize;
    int total;

public:
    //constructor destructor
    Character();
    Character(const Character&);
    virtual ~Character();
    
    //getters
    Card* getHand();
    int getHandSize();
    int getTotal();

    //setters
    void setHand(Card*);
    void setHandSize(int);
    void setTotal(int);

    //member functions
    void addCard(Card);
    void reset();

    //overloaded operators
    bool operator==(const Character&);
    bool operator>(const Character&);
};
#endif