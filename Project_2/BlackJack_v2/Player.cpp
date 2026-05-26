//Player.cpp

#include "Player.h"
#include <cstring>

using namespace std;

//Constructor
Player::Player()
{
	strcpy_s(name, "Player");
}

Player::Player(char c[])
{
	strcpy_s(name, c);
}

//set palyer name
void Player::setName(char c[])
{
	strcpy_s(name, c);
}

//return player name
char* Player::getName()
{
	return name;
}