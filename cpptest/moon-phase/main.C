#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <iostream>
#include "MoonPhase.h"

using namespace std;

int main(int argc, char *argv[])
{
	int year = atoi(argv[1]);
	int month = atoi(argv[2]);
	int day = atoi(argv[3]);

	for(int i=1;i<31;i++)
	{
		day = i;
		MoonPhase moonphase;
		moonphase.SetDate(year,month,day);
		moonphase.lt2mjd();
		moonphase.CalcPhase();
		double phase = moonphase.GetMoonPhase();
		double mjd = moonphase.GetMJD();

		printf("%d %d %d %.0lf 40587 %.0lf %d %.0lf\n",year,month,day,mjd,mjd-40587,int(mjd-40587)%30,phase);
	}
}
