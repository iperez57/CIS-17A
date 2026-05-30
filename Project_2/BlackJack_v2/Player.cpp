//Player.cpp

#include "Player.h"
#include <cstring>

using namespace std;

//Constructor
Player::Player()
{
	strcpy_s(name, "Player");

	chips = 100;
	currentBet = 0;
}

Player::Player(char c[])
{
	strcpy_s(name, c);

	chips = 100;
	currentBet = 0;
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