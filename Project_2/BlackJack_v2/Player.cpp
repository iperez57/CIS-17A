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
	if (b < 10)
	{
		throw InvalidBet();
	}
	if (b > chips)
	{
		throw NotEnoughChips();
	}
	currentBet = b;
}

void Player::setChips(int c)
{
	chips = c;
}

void Player::setGamesPlayed(int g)
{
	gamesPlayed = g;
}

void Player::setGamesWon(int g)
{
	gamesWon = g;
}

void Player::setGamesLoss(int g)
{
	gamesLoss = g;
}

void Player::setGamesTied(int g)
{
	gamesTied = g;
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

int Player::getGamesLoss()
{
	return gamesLoss;
}

int Player::getGamesTied()
{
	return gamesTied;
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

void Player::validBet()
{
	if (chips <= 0 )
	{
		throw NotEnoughChips();
	}
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

void Player::createPlayer(Player& player)
{
	char temp[20];

	cout << "Create Username: ";
	cin.ignore();
	cin.getline(temp, 20);
	cout << endl;

	player.setName(temp);
}

void Player::showInfo()
{
	cout << "Total: " << total << endl;
	cout << "Money: $" << getAvailableChips() << endl;
}

void Player::doubleDown()
{
	if (chips < currentBet)
	{
		throw NotEnoughChips();
	}

	currentBet *= 2;
}