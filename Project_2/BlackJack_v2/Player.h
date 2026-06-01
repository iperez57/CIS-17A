//Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Stats;

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
	static int gamesTied;

	friend class Stats;

public:
	//constructor
	Player();
	Player(char[]);

	//exceptions
	class InvalidBet {};
	class NotEnoughChips {};

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
	static int getGamesTied();

	//betting functions
	void winBet();
	void loseBet();
	int getAvailableChips();
	void tieBet();
	void validBet();

	//stat functions
	static void addGamePlayed();
	static void addWin();
	static void addLoss();
	static void addTie();

	//overloaded operators
	bool operator<=(int);

	void showInfo() override;
};
#endif