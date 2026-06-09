//SavingsClass.cpp

#include "SavingsAccount.h"
#include <iostream>

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
		FreqDeposit++;
	}
	else
	{
		if (Balance + f < 0)
		{
			cout << "Can't have a negative balance. WIthdrawal exceeds your balance.";
		}
		else
		{
			Withdraw(-f);
			FreqWithDraw++;
		}
	}
}

float SavingsAccount::Withdraw(float f)
{
	Balance -= f;
}

float SavingsAccount::Deposit(float f)
{
	Balance += f;
}

void SavingsAccount::toString()
{
	cout << "Balance = " << Balance << endl;
	cout << "Withdraw = " << FreqWithDraw << endl;
	cout << "Deposit = " << FreqDeposit << endl;
}