//Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
private:
	char name[20];

public:
	//constructor
	Player();
	Player(char[]);

	//setters
	void setName(char[]);

	//getters
	char* getName();
};

#endif