//Prob3TableInherited.h

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited :public Prob3Table<T> 
{
protected:
	T * augTable; //Augmented Table with sums
public:
	Prob3TableInherited(const char*, int, int); //Constructor
	~Prob3TableInherited() { delete[] augTable; }; //Destructor
	const T* getAugTable(void) { return augTable; };
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(const char* fileName, int r, int c) : Prob3Table<T>(fileName, r, c)
{
	augTable = new T[(this->rows + 1) * (this->cols + 1)];

	for (int i = 0; i < this->rows + 1; i++)
	{
		for (int j = 0; j < this->cols + 1; j++)
		{
			if (i < this->rows && j < this->cols)
			{
				augTable[i * (this->cols + 1) + j] = this->table[i * this->cols + j];
			}
			else if (i < this->rows && j == this->cols)
			{
				augTable[i * (this->cols + 1) + j] = this->rowSum[i];
			}
			else if (j < this->cols && i == this->rows)
			{
				augTable[i * (this->cols + 1) + j] = this->colSum[j];
			}
			else
			{
				augTable[i * (this->cols + 1) + j] = this->grandTotal;
			}
		}
	}
}
#endif