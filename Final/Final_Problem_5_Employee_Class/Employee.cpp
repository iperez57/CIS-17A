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
	float taxes;
	if (GrossPay < 500)
	{
		taxes = f * 0.10;
	}
	else if (GrossPay < 1000)
	{
		taxes = f * 0.20;
	}
	else
	{
		taxes = f * 0.30;
	}

	return taxes;
}

int Employee::setHoursWorked(int i)
{
	HoursWorked = i;
	return HoursWorked;
}

float Employee::setHourlyRate(float f)
{
	HourlyRate = f;
	return HourlyRate;
}

void Employee::toString()
{
	cout << "Name = " << MyName << " Job Title = " << JobTitle << endl;
	cout << "Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked << " Gross Pay = " << GrossPay << " Net Pay = " << NetPay << endl;
}

float Employee::getGrossPay(float hrPay, int hrWorked)
{
	if (hrWorked < 40)
	{
		GrossPay = hrPay * hrWorked;
	}
	else if (hrWorked < 50)
	{
		GrossPay = hrPay * 40;
		GrossPay += (hrWorked - 40) * hrPay * 1.5;
	}
	else
	{
		GrossPay = hrPay * 40;
		GrossPay += 10 * hrPay * 1.5;
		GrossPay += (hrWorked - 50) * hrPay * 2;
	}

	return GrossPay;
}

float Employee::getNetPay(float net)
{
	NetPay = GrossPay - Tax(GrossPay);
	return NetPay;
}