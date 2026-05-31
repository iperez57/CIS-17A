//Stats.cpp

#include "Stats.h"

using namespace std;

void Stats::displayStats(Player& p)
{
	cout << "Games Played: " << p.gamesPlayed << endl;
	cout << "Wins: " << p.gamesWon << endl;
	cout << "Losses: " << p.gamesLoss << endl;
	cout << "Ties: " << p.gamesTied << endl;
}