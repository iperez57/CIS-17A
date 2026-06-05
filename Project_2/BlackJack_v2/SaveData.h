//struct used for saving and loading game data

#ifndef SAVEDATA_H
#define SAVEDATA_H

#include "Card.h"

struct SaveData
{
    char name[20];

    //player bets
    int chips;
    int bet;

    Card playerHand[52];
    int playerHandSize;
    int playerTotal;

    Card dealerHand[52];
    int dealerHandSize;
    int dealerTotal;

    Card deckCards[52];
    int topCard;
    int size;

    //game stats
    int wins;
    int loss;
    int ties;
    int gamesPlayed;
};

#endif