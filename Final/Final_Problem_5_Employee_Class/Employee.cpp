//Employee.cpp

#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(const char name[], const char job[], float pay)
{
	strcpy_s(MyName, name);
	strcpy_s(JobTitle, job);

	if (pay > 0 && pay < 200)
	{
		HourlyRate = pay;
	}
	else
	{
		cout << "Unacceptable Hourly Rate" << endl;
		HourlyRate = 0;
	}
	HourlyRate = 0;
	HoursWorked = 0;
	GrossPay = 0;
	NetPay = 0;
}

double Employee::Tax(float f)
{
	float taxes;
	if (f < 500)
	{
		taxes = f * 0.10;
	}
	else if (f < 1000)
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
	if (i > 0 && i < 84)
	{
		HoursWorked = i;
	}
	else
	{
		cout << "Unacceptable Hours Worked" << endl;
	}
	return HoursWorked;
}

float Employee::setHourlyRate(float f)
{
	if (f > 0 && f < 200)
	{
		HourlyRate = f;
	}
	else
	{
		cout << "Unacceptable Hourly Rate" << endl;
	}
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
	net = GrossPay - Tax(GrossPay);
	NetPay = net;
	return NetPay;
}

float Employee::CalculatePay(float pay, int hr)
{
	return getNetPay(getGrossPay(setHourlyRate(pay), setHoursWorked(hr)));
}