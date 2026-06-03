//Dealer.h

#ifndef DEALER_H
#define DEALER_H

#include "Character.h"

class Dealer : public Character
{
public:
	void dealerCardMsg();
	void dealerThinkingMsg();
	void dealerHitMsg();
	void dealerStandMsg();
	void dealerHiddenHand();

	void showInfo() override;
};
#endif
