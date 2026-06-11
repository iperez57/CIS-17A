//Prob4.cpp

#include "Prob4.h"
#include <iostream>
#include <cmath>
#include <string>

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
		try
		{
			if (Balance + f < 0)
			{
				throw BalanceException();
			}
			else
			{
				Withdraw(-f);
				FreqWithDraw++;
			}
		}
		catch (BalanceException)
		{
			cout << "Can't have a negative balance. WIthdrawal exceeds your balance." << endl;
		}
	}
}

float SavingsAccount::Withdraw(float f)
{
	Balance -= f;
	return Balance;
}

float SavingsAccount::Deposit(float f)
{
	Balance += f;
	return Balance;
}

string SavingsAccount::toString()
{
	string ss;

	ss += "Balance = " + to_string(Balance) + "\n";
	ss += "Withdraw = " + to_string(FreqWithDraw) + "\n";
	ss += "Deposit = " + to_string(FreqDeposit) + "\n";

	return ss;
}

float SavingsAccount::Total(float saveint, int time)
{
	float result = Balance;
	for (int i = 0; i < time; i++)
	{
		result *= (1 + saveint);
	}

	return result;
}

float SavingsAccount::TotalRecursive(float saveint, int time)
{
	if (time == 0)
	{
		return Balance;
	}

	return (1 + saveint) * TotalRecursive(saveint, time - 1);
}