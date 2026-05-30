//Player.cpp

#include "Player.h"
#include <cstring>

using namespace std;

//Constructor
Player::Player()
{
	strcpy_s(name, "Player");
	//betting variables
	chips = 100;
	currentBet = 0;
	//stat variables
	gamesPlayed = 0;
	gamesWon = 0;
	gamesLoss = 0;
}

Player::Player(char c[])
{
	strcpy_s(name, c);
	//betting variables
	chips = 100;
	currentBet = 0;
	//stat variables
	gamesPlayed = 0;
	gamesWon = 0;
	gamesLoss = 0;
}

//setters
void Player::setName(char c[])
{
	strcpy_s(name, c);
}

void Player::setBet(int b)
{
	currentBet = b;
}

//getters
char* Player::getName()
{
	return name;
}

int Player::getBet()
{
	return currentBet;
}

int Player::getChips()
{
	return chips;
}

int Player::getGamesPlayed()
{
	return gamesPlayed;
}

int Player::getGamesWon()
{
	return gamesWon;
}

int Player::getGamesLost()
{
	return gamesLoss;
}


//betting functions
void Player::winBet()
{
	chips += currentBet;
	currentBet = 0;
}

void Player::loseBet()
{
	chips -= currentBet;
	currentBet = 0;
}

int Player::getAvailableChips()
{
	return chips - currentBet;
}

//stat functions
void Player::addGamePlayed()
{
	gamesPlayed++;
}

void Player::addWin()
{
	gamesWon++;
}

void Player::addLoss()
{
	gamesLoss++;
}