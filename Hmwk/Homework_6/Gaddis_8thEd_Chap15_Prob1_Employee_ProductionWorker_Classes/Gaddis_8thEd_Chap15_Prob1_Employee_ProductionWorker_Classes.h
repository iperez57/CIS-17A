/*
 * File:   Gaddis_8thEd_Chap15_Prob1_Employee_ProductionWorker_Classes.h
 * Author: Isaac Perez
 * Created on 05/21/2026
 * Purpose:  use class inheritance
 */

#ifndef Gaddis_8thEd_Chap15_Prob1_Employee_ProductionWorker_Classes_H
#define Gaddis_8thEd_Chap15_Prob1_Employee_ProductionWorker_Classes_H
#include <iostream>

using namespace std;

class Employee
{
private:
	string name;
	string date;
	int number;

public:
	Employee(string, string, int);

	void setName(string);
	void setDate(string);
	void setNumber(int);

	string getName();
	string getDate();
	int getNumber();


};

//Function Implementations

Employee::Employee(string n, string d, int num)
{
	name = n;
	date = d;
	number = num;
}

void Employee::setName(string n)
{
	name = n;
}

void Employee::setDate(string d)
{
	date = d;
}

void Employee::setNumber(int num)
{
	number = num;
}

string Employee::getName()
{
	return name;
}

string Employee::getDate()
{
	return date;
}

int Employee::getNumber()
{
	return number;
}
#endif