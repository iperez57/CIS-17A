//Employee.cpp

#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(char name[], char job[], float pay)
{
	strcpy(MyName, name);
	strcpy(JobTitle, job);

	HourlyRate = pay;
	HoursWorked = 0;
	GrossPay = 0;
	NetPay = 0;
}

double Employee::Tax(float f)
{
	if (GrossPay < 500)
	{

	}
	else if (GrossPay < 1000)
	{

	}
	else
	{

	}
}

int Employee::setHoursWorked(int i)
{
	HoursWorked = i;
}

float Employee::setHourlyRate(float f)
{
	HourlyRate = f;
}