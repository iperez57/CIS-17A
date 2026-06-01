//Player.cpp

#include "Player.h"
#include <cstring>
#include <iostream>

using namespace std;

int Player::gamesPlayed = 0;
int Player::gamesWon = 0;
int Player::gamesLoss = 0;
int Player::gamesTied = 0;

//Constructor
Player::Player()
{
	strcpy_s(name, "Player");
	//betting variables
	chips = 100;
	currentBet = 0;
}

Player::Player(char c[])
{
	strcpy_s(name, c);
	//betting variables
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

void Player::tieBet()
{
	currentBet = 0;
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

void Player::addTie()
{
	gamesTied++;
}

//overloaded operator
bool Player::operator<=(int amount)
{
	return chips <= amount;
}

void Player::showInfo()
{
	cout << "Total: " << total << endl;
	cout << "Money: $" << chips << endl;
}