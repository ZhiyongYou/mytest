#include <iostream>
#include <stdio.h>
#include <vector>
#include "Time.h"
#include "TAI.h"

int main(int argc, char *argv[])
{
	TAI time1;
	time1.setYear(atof(argv[1]));
	printf("year1:%d\n",time1.getYear());

	TAI time2;
	time2 = time1;
	printf("year2:%d\n",time2.getYear());

	printf("IsleapYear:%d\n",Time::leapYear(time1));
	printf("year1:%d year2:%d\n",time1.getYear(),time2.getYear());

	return 0;
}
