#include "Time.h"

Time::Time()
{

}

Time::~Time()
{

}

void Time::setYear(int y)
{
	year = y;
}

void Time::setMonth(int mon)
{
	month = mon;
}

void Time::setDay(int d)
{
	day = d;
}


bool Time::leapYear(const Time& time)
{
	int mod4, mod100, mod400;
	mod4 = time.year % 4;
	mod100 = time.year % 100;
	mod400 = time.year % 400;

	if(mod4==0)
		return 1;
	else{
		if(mod100==0 && mod400==0)
			return 1;
		else
			return 0;
	}
}
