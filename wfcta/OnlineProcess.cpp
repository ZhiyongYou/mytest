#include <stdlib.h>
#include <iostream>
#include "OnlineProcess.h"
#include <TPad.h>
#include <TStyle.h>
#include "cameraTemperature.h"

using namespace std;

OnlineProcess::OnlineProcess()
{
	OnlineProcess::Init();
	OnlineProcess::SetImage();
}

OnlineProcess::~OnlineProcess()
{

}

void OnlineProcess::Init()
{
	iTel = -1;
	rb_Time = -1000;
	rb_time = -1000;
	for(int i=0;i<1024;i++){
		HV[i] = -1000;
		PreTemp[i] = -1000;
	}
	for(int i=0;i<89;i++){
		avePreTemp[i] = -1000;
		avePreTempcount[i] = 0;
	}
}

/*******************************************
 * change rabbittime to Gregorian calendar *
 * *****************************************/
void OnlineProcess::GetTime()
{
	double MJD19700101 = 40587;
	double TAI2UTC = 37;
	mjd = MJD19700101 + (rb_Time + rb_time*20/1000000000. - TAI2UTC)/86400;

	int j;
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
}


/******************************
 * dealing with PreTemperature*
 * ****************************/
void OnlineProcess::SetHVTempPar(double *temp0)
{
	for(int i=0;i<1024;i++)
	{
		PreTemp[i] = temp0[i];
	}
}

void OnlineProcess::CalcNextHV()
{
	short mSC,mChannel;
	short SIPM;
	vector<double> pre_temp;
	for(int FF=1;FF<9;FF++)
	{
		for(int DB=1;DB<9;DB++)
		{
			short SC=FF+10*DB;
			double aveallPreTemp=0;
			pre_temp.clear();
			for(int CH=1;CH<17;CH++)
			{
				SC_Channel2SiPMtemp(SC,CH,&SIPM);
				aveallPreTemp += PreTemp[SIPM];
				pre_temp.push_back(PreTemp[SIPM]);
			}

			if(FF==2&&DB==8){printf("%lf\n",aveallPreTemp);}
			aveallPreTemp /= 16.;
			sort(pre_temp.begin(),pre_temp.end());
			//int temp_len = 3;//pre_temp.size();
			int temp_len = pre_temp.size();
			if(temp_len==0){continue;}
			for(int ii=3;ii<temp_len-3;ii++)
			{
				avePreTemp[SC] += pre_temp.at(ii);
				avePreTempcount[SC]++;
			}
			if(avePreTempcount[SC]>0)
			{
				avePreTemp[SC] += 1000;
				if(FF==2&&DB==8){printf("%d %lf\n",avePreTempcount[SC],avePreTemp[SC]);}
				avePreTemp[SC] /= avePreTempcount[SC];
			}
			if(FF==2&&DB==8)
				printf("%lf %lf\n",avePreTemp[SC],aveallPreTemp);
		}
	}
	//get corrected temperature for each sipm, 
	//if the temperature of the sipm is not read back, use average temperature as replacement
	//if the whole subcluster does not read back temperature, set correctTemp to 20
	for(int i=0;i<1024;i++){
		SiPM2SC_Channeltemp(i, &mSC, &mChannel);
		if(avePreTempcount[mSC]>0){
			correctTemp[i] = avePreTemp[mSC];
		}
		else{
			correctTemp[i] = -1000;
		}
	}
	/*
	//calc next hv
	short ff,dd,esipm;
	double eHV[1024]={0};
	for(int i=0;i<1024;i++){
		SiPM2SC_Channeltemp(i, &mSC, &mChannel);
		ff = mSC%10;
		dd = mSC/10;
		SC_Channel2eSiPMtemp(ff,dd,mChannel,&esipm);
		cor_Temp[esipm-1] = correctTemp[i];
		eHV[esipm-1] = HV[i];
	}

	double dTemp[1024]={0};
	for(int i=0;i<1024;i++){
		dTemp[i] = cor_Temp[i] - Temp0[i];
		nextHV[i] = HV0[i] + hv_t_fac[i] * dTemp[i];
		if(i==1||i==101||i==1023){
			eSiPM2SC_Channeltemp(i+1, &mSC, &mChannel);
			printf("sipm:%4d SC:%d channel:%d HV_rback:%lf Temp0:%lf Temp1:%lf deltaT:%lf factor:%lf HV0:%lf hv_set:%lf\n",i,mSC,mChannel,eHV[i],Temp0[i],cor_Temp[i],dTemp[i],hv_t_fac[i],HV0[i],nextHV[i]);
		}
		if(dTemp[i]>3&&Temp0[i]!=20){
			cor_Temp[i] = Temp0[i];
			nextHV[i] = HV0[i];
		}
	}
	*/
}

/***********************
 * draw clb temperature*
 * *********************/

/*********************************
 * * set x and y, unit in degree *
 * *******************************/
void OnlineProcess::SetImage()
{
	int PixI,PixJ;
	for(int k=0;k<1024;k++)
	{
		PixI = (k) / PIX;
		PixJ = (k) % PIX;
		if(PixI%2==0)  {ImageX[k] = PixJ+0.5-PIX/2.0;}
		if(PixI%2==1)  {ImageX[k] = PixJ+1-PIX/2.0;}
		ImageY[k] = (PIX/2.0-PixI) - 1/2.0;

		ImageX[k] = ImageX[k]*16/32.;
		ImageY[k] = ImageY[k]*16/32.;// "-" is WCDA map, "+" is WFCTA map

		ImageX[k] -= 0.31;
		ImageY[k] -= 0.28;
	}

}



