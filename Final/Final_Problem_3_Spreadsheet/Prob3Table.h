//Prob3Table.h

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

template<class T>
class Prob3Table {
protected:
	int rows; //Number of rows in the table
	int cols; //Number of cols in the table
	T* rowSum; //RowSum array
	T* colSum; //ColSum array
	T* table; //Table array
	T grandTotal; //Grand total
	void calcTable(void); //Calculate all the sums
public:
	Prob3Table(const char*, int, int); //Constructor then Destructor
	~Prob3Table() { delete[] table;delete[] rowSum;delete[] colSum; };
	const T* getTable(void) { return table; };
	const T* getRowSum(void) { return rowSum; };
	const T* getColSum(void) { return colSum; };
	T getGrandTotal(void) { return grandTotal; };
};

template<class T>
Prob3Table<T>::Prob3Table(const char* fileName, int r, int c)
{
	rows = r;
	cols = c;
	table = new T[rows * cols];
	rowSum = new T[rows]();
	colSum = new T[cols]();
	grandTotal = 0;
	ifstream file(fileName);
	for (int i = 0; i < rows * cols; i++)
	{
		file >> table[i];
	}
	file.close();

	calcTable();
}

template<class T>
void Prob3Table<T>::calcTable()
{
	grandTotal = 0;
	for (int i = 0; i < rows; i++)
	{
		rowSum[i] = 0;

		for (int j = 0; j < cols; j++)
		{
			rowSum[i] += table[i * cols + j];
		}
	}

	for (int i = 0; i < cols; i++)
	{
		colSum[i] = 0;

		for (int j = 0; j < rows; j++)
		{
			colSum[i] += table[j * cols + i];
		}
	}

	for (int i = 0; i < rows * cols; i++)
	{
		grandTotal += table[i];
	}
}

#endif