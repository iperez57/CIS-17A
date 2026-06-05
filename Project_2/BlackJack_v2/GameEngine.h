#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

class GameEngine
{
public:
    void gameLoop(Deck&, Player&, Dealer&, const int, bool&, bool&);
    void loadGame(Deck&, Player&, Dealer&);

private:
    // core flow
    void startingDraw(Deck&, Player&, Dealer&);
    void hit(Deck&, Player&);
    void hit(Deck&, Dealer&);

    void dealerTurn(Deck&, Dealer&, const int);
    void checkWinner(Player&, Dealer&, const int);
    bool replay(Deck&, Player&, Dealer&, bool&);
    void dealCard(Deck&, Player&);
    void dealCard(Deck&, Dealer&);

    void saveGame(Deck&, Player&, Dealer&);

    template <class T>
    void displayHand(T& obj)
    {
        for (int i = 0; i < obj.getHandSize(); i++)
        {
            cout << obj.getHand()[i].rank << " of " << obj.getHand()[i].suit << endl;
        }
        obj.showInfo();
    }
};
#endif