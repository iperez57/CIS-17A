/*
 * File:   MilTime.h
 * Author: Isaac Perez
 * Created: 05/22/2026
 * Purpose:  use class inheritance
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime : public Time
{
private:
	int milHours;
	int milSeconds;
	int milMinutes;
public:
	MilTime(int, int, int);

	void setTime(int, int, int);

	int getMilHour();
	int getStandHr();
};
MilTime::MilTime(int mH, int mM, int mS)
{
	setTime(mH, mM, mS);
}

void MilTime::setTime(int mH, int mM, int mS)
{
	if (hour > 12)
	{
		hour -= 12;
	}
	hour = mH;
	min = mM;;
	sec = mS;

}
int MilTime::getMilHour()
{
	return milHours;
}

int MilTime::getStandHr()
{
	return hour;
}


#endif