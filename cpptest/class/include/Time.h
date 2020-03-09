#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

class Time{
public:
	Time();
	~Time();

	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	int getYear()  {return year;};
	int getMonth()  {return month;};
	int getDay()  {return day;};

	static bool leapYear(const Time& time);
	
protected:
	enum {centry=100};//static const int m2cm=100;//use enum hack instead of static const
	enum {leapsecond=37};
	int year;
	int month;
	int day;
};

#endif // TIME_H
