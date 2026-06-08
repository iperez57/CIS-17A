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
#endif