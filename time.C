#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <time.h>
#include "TMath.h"

double MJD19700101 = 40587;
double TAI2UTC = 37;
using namespace std;

void rbtime2lt(Long64_t rabbitTime, double rabbittime)
{
	time_t rawtime;
	time_t utc = rabbitTime-TAI2UTC;
	struct tm *info;
	info = localtime(&utc);
	int year = 1900 + info->tm_year;
	int month = info->tm_mon+1;
	int day = info->tm_mday;
	int hour = info->tm_hour;
	int minite = info->tm_min;
	int second = info->tm_sec;
	printf("%d %d %d %d:%d:%d\n",year,month,day,hour,minite,second);

}

//change rabbit time to local time
void rabbittime2lt(Long64_t rabbitTime, double rabbittime)
{
	double mjd;
	mjd = MJD19700101 + (rabbitTime + rabbittime*20/1000000000. - TAI2UTC)/86400;

	int j;
	int year,month,day,hour,minite,second;
	double fd, d;
	long jd, n4, nd10;
	/* Check if date is acceptable */
	if ( ( mjd <= -2395520.0 ) || ( mjd >= 1e9 ) ) {
		j = -1;
	}
	else {
		j = 0;
		/* Separate day and fraction */
		fd = (mjd)>0.0?mjd-floor(mjd):mjd+floor(-mjd);
		if ( fd < 0.0 ) fd += 1.0;
		d = mjd - fd;
		d = d<0.0?ceil(d):floor(d);
		/* Express day in Gregorian calendar */
		jd = (long)d + 2400001;
		n4 = 4L*(jd+((6L*((4L*jd-17918L)/146097L))/4L+1L)/2L-37L);
		nd10 = 10L*(((n4-237L)%1461L)/4L)+5L;
		year = (int) (n4/1461L-4712L);
		month = (int) (((nd10/306L+2L)%12L)+1L);
		day = (int) ((nd10%306L)/10L+1L);
		j = 0;
		hour = int(fd * 24 + 8);
		minite = int((fd*24+8 - hour)*60);
		second = int(((fd*24+8-hour)*60-minite)*60);
		day += hour/24;
		hour = hour%24;
	}

	printf("%.20lf %d %d %d %lf ( %d %d %d )\n",mjd,year,month,day,fd,hour,minite,second);
}

void slaCldj ( int iy, int im, int id)
{
   long iyL, imL;
   double djm;
   int j;

   /* Month lengths in days */
   static int mtab[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   /* Validate year */
   if ( iy < -4699 ) { j = 1; return; }
   /* Validate month */
   if ( ( im < 1 ) || ( im > 12 ) ) { j = 2; return; }
   /* Allow for leap year */
   mtab[1] = ( ( ( iy % 4 ) == 0 ) &&
		   ( ( ( iy % 100 ) != 0 ) || ( ( iy % 400 ) == 0 ) ) ) ?
	   29 : 28;

   /* Validate day */
   j = ( id < 1 || id > mtab[im-1] ) ? 3 : 0;
   /* Lengthen year and month numbers to avoid overflow */
   iyL = (long) iy;
   imL = (long) im;
   /* Perform the conversion */
   djm = (double)
	   ( ( 1461L * ( iyL - ( 12L - imL ) / 10L + 4712L ) ) / 4L
		 + ( 306L * ( ( imL + 9L ) % 12L ) + 5L ) / 10L
		 - ( 3L * ( ( iyL - ( 12L - imL ) / 10L + 4900L ) / 100L ) ) / 4L
		 + (long) id - 2399904L );

   //long double rb_time;
   //(mjd - MJD19700101)*86400 + TAI2UTC = rabbitTime + rabbittime*20/1000000000.;
   Long64_t rabbitTime = (djm - MJD19700101)*86400 + TAI2UTC;
   printf("%lf %lld \n",djm,rabbitTime);
}
