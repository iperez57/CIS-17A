//Prob2Sort.h
//This class sorts arrays either ascending or descending

#ifndef PROB2SORT_H
#define PROB2SORT_H

template<class T>
class Prob2Sort {
private:
	int* index; //Index that is utilized
	//in the sort
public:
	Prob2Sort(); //Constructor
	~Prob2Sort(); //Destructor
	T* sortArray(const T*, int, bool); //Sorts a single column array
	T* sortArray(const T*, int, int, int, bool);//Sorts a 2 dimensional array
	//represented as a 1 dim array
};

template<class T>
Prob2Sort<T>::Prob2Sort()
{
	index = nullptr;
}

template<class T>
Prob2Sort<T>::~Prob2Sort()
{
	delete[] index;
}

template<class T>
T* Prob2Sort<T>::sortArray(const T*, int, bool)
{

}

template<class T>
T* Prob2Sort<T>::sortArray(const T* ch2p, int rows, int cols, int colSort, bool ascending)
{
	index = new int[rows];
	colSort = colSort - 1;

	for (int i = 0; i < rows; i++)
	{
		index[i] = i;
	}

	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = i + 1 ; j < rows; j++)
		{
			if (ascending)
			{
				if (ch2p[index[i] * cols + colSort] > ch2p[index[j] * cols + colSort])
				{
					int temp = index[i];
					index[i] = index[j];
					index[j] = temp;

				}
			}
			else
			{
				if (ch2p[index[i] * cols + colSort] < ch2p[index[j] * cols + colSort])
				{
					int temp2 = index[i];
					index[i] = index[j];
					index[j] = temp2;
				}
			}

		}
	}

	T* sorted = new T[rows * cols];

	for (int i = 0;i < rows;i++) 
	{
		for (int j = 0;j < cols;j++)
		{
			sorted[i * cols + j] = ch2p[index[i] * cols + j];
		}
	}

	return sorted;
}
#endif