//Prob1Random.cpp

#include "Prob1Random.h"

using namespace std;

Prob1Random::Prob1Random(const char c, const char* k)
{
	nset = c;
	set = new char[nset];
	freq = new int[nset]();
	numRand = 0;
}

Prob1Random::~Prob1Random()
{
	delete[] set;
	delete[] freq;
}

char Prob1Random::randFromSet()
{

}