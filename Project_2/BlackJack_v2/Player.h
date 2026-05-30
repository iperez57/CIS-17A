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

	//static variables
	static int gamesPlayed;
	static int gamesWon;
	static int gamesLoss;

public:
	//constructor
	Player();
	Player(char[]);

	//setters
	void setName(char[]);
	void setBet(int);

	//getters
	char* getName();
	int getChips();
	int getBet();
	static int getGamesPlayed();
	static int getGamesWon();
	static int getGamesLost();

	//betting functions
	void winBet();
	void loseBet();
	int getAvailableChips();

	//stat functions
	static void addGamePlayed();
	static void addWin();
	static void addLoss();

};

#endif