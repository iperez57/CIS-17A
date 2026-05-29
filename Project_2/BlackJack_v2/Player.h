//Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
private:
	char name[20];
	int chips;
	int currentBet;

public:
	//constructor
	Player();
	Player(char[]);

	//setters
	void setName(char[]);
	void setBet(int);
	void setChips(int);

	//getters
	char* getName();
	int getChips();
	int getBet();

	//betting functions
	void winBet();
	void loseBet();
};

#endif