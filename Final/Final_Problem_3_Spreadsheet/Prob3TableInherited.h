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
	Prob3TableInherited(char*, int, int); //Constructor
	~Prob3TableInherited() { delete[] augTable; }; //Destructor
	const T* getAugTable(void) { return augTable; };
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* fileName, int r, int c)
{
	augTable = new T[(this->rows + 1) * (this->cols + 1)];
}
#endif