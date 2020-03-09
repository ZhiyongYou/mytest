#ifndef ONLINEPROCESS_H
#define ONLINEPROCESS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

#define PIX 32

class OnlineProcess 
{
	public:
		OnlineProcess();
		~OnlineProcess();

	private:
		double mjd;
		float avePreTemp[89];
		int avePreTempcount[89];

	public:
		int iTel;
		int ievt;
		long rb_Time;
		double rb_time;
		int n_sipms;	
		int year;
		int month;
		int day;
		int hour;
		int minite;
		int second;
		float HV[1024];
		float PreTemp[1024];
		double ImageX[1024];
		double ImageY[1024];

		double correctTemp[1024];
		double cor_Temp[1024];
		double nextHV[1024];
		double hv_t_fac[1024];
		double HV0[1024];
		double Temp0[1024];

		void Init();
		void GetTime();
		void SetImage();
		void SetHVTempPar(double *temp0);
		void CalcNextHV();

};

#endif // STATUSSHOW_H
