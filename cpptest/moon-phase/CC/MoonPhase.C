#include <stdlib.h>
#include <cmath>
#include <iostream>
#include "MoonPhase.h"

using namespace std;

const double MoonPhase::mjd_start=40587;
const double MoonPhase::phase_start=7;
MoonPhase::MoonPhase()
{
}

MoonPhase::~MoonPhase()
{
}

void MoonPhase::lt2mjd()
{
	long iyL, imL;
	int j;
	int mtab[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	/* Validate year */
	if ( year < -4699 ) { j = 1; }
	/* Validate month */
	if ( ( month < 1 ) || ( month > 12 ) ) { j = 2; }
	/* Allow for leap year */
	mtab[1] = ( ( ( year % 4 ) == 0 ) &&
			( ( ( year % 100 ) != 0 ) || ( ( year % 400 ) == 0 ) ) ) ?
		29 : 28;
	/* Validate day */
	j = ( day < 1 || day > mtab[month-1] ) ? 3 : 0;

	/* Lengthen year and month numbers to avoid overflow */
	iyL = (long) year;
	imL = (long) month;

	/* Perform the conversion */
	djm = (double)
		( ( 1461L * ( iyL - ( 12L - imL ) / 10L + 4712L ) ) / 4L
		  + ( 306L * ( ( imL + 9L ) % 12L ) + 5L ) / 10L
		  - ( 3L * ( ( iyL - ( 12L - imL ) / 10L + 4900L ) / 100L ) ) / 4L
		  + (long) day - 2399904L );
}

void MoonPhase::CalcPhase()
{
	int iphase;
	long deltaDate;
	double deltaPhase;

	deltaDate = long(djm - mjd_start)%30;
	if(deltaDate>14)
		deltaDate = 29 - deltaDate;
	deltaPhase = deltaDate%15;
	iphase = int(phase_start + deltaPhase)%16;
	phase = (double) iphase;
}

void MoonPhase::SetDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
