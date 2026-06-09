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
