/*
 * File:   MilTime.h
 * Author: Isaac Perez
 * Created: 05/23/2026
 * Purpose:  use exceptions
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime : public Time
{
private:
	int milHours;
	int milSeconds;

public:
	class BadHour {};
	class BadSeconds {};

	MilTime(int, int);

	void setTime(int, int);

	int getMilHour();
	int getStandHr();
};
MilTime::MilTime(int mH, int mS)
{
	setTime(mH, mS);
}

void MilTime::setTime(int mH, int mS)
{
	if (mH < 0 || mH > 2359 || mH % 100 > 59)
	{
		throw BadHour();
	}
	if (mS < 0 || mS > 59)
	{
		throw BadSeconds();
	}
	milHours = mH;
	milSeconds = mS;
	hour = mH / 100;

	if (hour > 12)
	{
		hour -= 12;
	}
	min = mH % 100;
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