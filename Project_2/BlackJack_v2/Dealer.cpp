//Dealer.cpp

#include "Dealer.h"
#include <iostream>

using namespace std;

void Dealer::dealerCardMsg()
{
	cout << "Dealers Cards: " << endl;
}

void Dealer::dealerHitMsg()
{
	cout << "Dealer hits" << endl;
}

void Dealer::dealerStandMsg()
{
	cout << "Dealer stands" << endl;
}

void Dealer::dealerThinkingMsg()
{
	cout << "Dealer is thinking ..." << endl;
}

void Dealer::dealerHiddenHand()
{
	cout << hand[0].rank << " of " << hand[0].suit << endl;

	cout << "[Hidden Card]" << endl;
}

void Dealer::showInfo()
{
	cout << "Total: " << total << endl;
}