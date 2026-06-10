//Prob1.cpp

#include "Prob1.h"
#include <cstdlib>

using namespace std;

Prob1Random::Prob1Random(const char n, const char* rndseq)
{
	nset = n;
	set = new char[nset];
	freq = new int[nset]();
	numRand = 0;

	for (int i = 0; i < nset; i++)
	{
		set[i] = rndseq[i];
	}
}

Prob1Random::~Prob1Random()
{
	delete[] set;
	delete[] freq;
}

char Prob1Random::randFromSet()
{
	int index = rand() % nset;

	freq[index]++;
	numRand++;

	return set[index];
}

int* Prob1Random::getFreq() const
{
	return freq;
}

char* Prob1Random::getSet() const
{
	return set;
}

int Prob1Random::getNumRand() const
{
	return numRand;
}