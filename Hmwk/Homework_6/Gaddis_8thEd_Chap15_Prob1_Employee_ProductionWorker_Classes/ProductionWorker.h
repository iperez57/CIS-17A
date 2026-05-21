/*
 * File:   ProductionWorker.h
 * Author: Isaac Perez
 * Created on 05/14/2026
 * Purpose:  use class inheritance
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include <iostream>
#include "Employee.h"

using namespace std;

class ProductionWorker : public Employee
{
private:
	int shift;
	double payRate;

public:
	ProductionWorker(string, string, int, int, double);

	void setShift(int);
	void setPayRate(double);

	int getShift();
	double getPayRate();
};
//Function Implementations

ProductionWorker::ProductionWorker(string n, string d, int num, int s, double p) : Employee(n, d, num)
{
	shift = s;
	payRate = p;
}

void ProductionWorker::setShift(int s)
{
	shift = s;
}

void ProductionWorker::setPayRate(double p)
{
	payRate = p;
}

int ProductionWorker::getShift()
{
	return shift;
}

double ProductionWorker::getPayRate()
{
	return payRate;
}

#endif