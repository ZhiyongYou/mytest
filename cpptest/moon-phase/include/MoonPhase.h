#ifndef __MOONPHASE__
#define __MOONPHASE__
#include <stdint.h>

class MoonPhase
{
	protected:
		static const double mjd_start;
		static const double phase_start;
		int year;
		int month;
		int day;
		double djm;
		double phase;

	public:
		MoonPhase();
		~MoonPhase();

		void SetDate(int y, int m, int d);
		void lt2mjd();
		void CalcPhase();
		double GetMoonPhase()	{return phase;};
		double GetMJD()	{return djm;};

};

#endif //__MOONPHASE__
