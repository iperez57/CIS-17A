//SavingsClass.cpp

#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(float f)
{
	if (f > 0)
	{
		Balance = f;
	}
	else
		Balance = 0;
	FreqDeposit = 0;
	FreqWithDraw = 0;
}

void SavingsAccount::Transaction(float f)
{
	if (f > 0)
	{
		Deposit(f);
	}
	else
		Withdraw(f);
}