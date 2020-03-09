#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <ctime>
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"

using namespace std;

struct wfctatime{
	double event_ievt;
	long long event_alltime;
	//double event_time;
};

int comp(const wfctatime &s1,const wfctatime &s2){
	    return s1.event_alltime<s2.event_alltime;
}

wfctatime tel01event;
vector<wfctatime> tel01events;

int iTel;
Long64_t rabbitTime;
double rabbittime;
vector<int> *isipm = new vector<int>();
vector<double> *sipmpe = new vector<double>();
vector<double> *sipmt = new vector<double>();
vector<int> *cellig = new vector<int>();
vector<double> *cellpe = new vector<double>();
vector<double> *cellt = new vector<double>();
vector<int> *hitid = new vector<int>();
vector<double> *hitpart = new vector<double>();
vector<double> *hitt = new vector<double>();
vector<int> *hitmode = new vector<int>();
int IsKm2aEvent;
int IsWcdaEvent;
double wcda_zenc;
double wcda_azic;
double wcda_xc1;
double wcda_yc1;
double wcda_zen;
double wcda_azi;
double wcda_xc;
double wcda_yc;
float km2a_xc;
float km2a_yc;
float km2a_phi;
float km2a_theta;

void setWFCTAEvent(const vector<wfctatime> &televents, TTree **lhTree);
void slaCldj ( int iy, int im, int id, double *djm, int *j );

int main(int argc, char *argv[])
{
	if(argc<0) {
		printf("Usage: %s outroot wfcta01.txt wfcta02.txt wfcta03.txt wfcta04.txt wfcta05.txt wfcta06.txt\n", argv[0]);
		return 1;
	}

	cout<<"begin time:"<<time(0)<<endl;
	int i;

	//////////////////////////////////////////////////
	//              Read File                 //
	//////////////////////////////////////////////////
	int year=2019;
	int mon=11;
	int day=23;
	int hour=22;
	int minite=0;
	double mjd;
	int jjj;
	slaCldj ( year, mon, day, &mjd, &jjj );
	long long TimeStart = (mjd-40587)*86400 + (hour-8)*3600 + minite*60 + 37;
	long long TimeEnd = TimeStart + 600;
	printf("TimeStart:%lld TimeEnd:%lld\n",TimeStart,TimeEnd);

	FILE *fp;
	char telfile[500];
	int ievent;
	int ifile;
	int ievt_selected;
	long long wfcta_time;
	double wfcta_ievent;
	int timeside=0;
	printf("TimeStart:%lld TimeEnd:%lld\n",TimeStart,TimeEnd);
	////////////////////////////////////////////////
	//     Read Tel 01     /////////////////////////
	////////////////////////////////////////////////
	TFile *tel01TFile[100];
	TTree *LHAASOEventTree01[100];
	fp = fopen(argv[1],"r");
	ifile=0;
	tel01events.clear();
	while(!feof(fp))
	{
		ievt_selected=0;
		fscanf(fp,"%s\n",telfile);
		tel01TFile[ifile] = TFile::Open(telfile,"READ");
		printf("inputing wfcta file -> %s\n",telfile);
		if(tel01TFile[ifile]->IsZombie()||tel01TFile[ifile]->GetEND()<50)
		{
			printf("wfcta file error!!\n");
			return 1;
		}
		LHAASOEventTree01[ifile] = (TTree *)tel01TFile[ifile]->Get("event");
		LHAASOEventTree01[ifile]->SetBranchAddress("iTel",&iTel);
		LHAASOEventTree01[ifile]->SetBranchAddress("rabbitTime",&rabbitTime);
		LHAASOEventTree01[ifile]->SetBranchAddress("rabbittime",&rabbittime);
		LHAASOEventTree01[ifile]->SetBranchAddress("isipm",&isipm);
		LHAASOEventTree01[ifile]->SetBranchAddress("sipmpe",&sipmpe);
		LHAASOEventTree01[ifile]->SetBranchAddress("sipmt",&sipmt);
		LHAASOEventTree01[ifile]->SetBranchAddress("cellig",&cellig);
		LHAASOEventTree01[ifile]->SetBranchAddress("cellpe",&cellpe);
		LHAASOEventTree01[ifile]->SetBranchAddress("cellt",&cellt);
		LHAASOEventTree01[ifile]->SetBranchAddress("hitid",&hitid);
		LHAASOEventTree01[ifile]->SetBranchAddress("hitpart",&hitpart);
		LHAASOEventTree01[ifile]->SetBranchAddress("hitt",&hitt);
		LHAASOEventTree01[ifile]->SetBranchAddress("hitmode",&hitmode);
		LHAASOEventTree01[ifile]->SetBranchAddress("IsKm2aEvent",&IsKm2aEvent);
		LHAASOEventTree01[ifile]->SetBranchAddress("IsWcdaEvent",&IsWcdaEvent);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_zenc",&wcda_zenc);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_azic",&wcda_azic);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_xc1",&wcda_xc1);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_yc1",&wcda_yc1);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_zen",&wcda_zen);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_azi",&wcda_azi);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_xc",&wcda_xc);
		LHAASOEventTree01[ifile]->SetBranchAddress("wcda_yc",&wcda_yc);
		LHAASOEventTree01[ifile]->SetBranchAddress("km2a_xc",&km2a_xc);
		LHAASOEventTree01[ifile]->SetBranchAddress("km2a_yc",&km2a_yc);
		LHAASOEventTree01[ifile]->SetBranchAddress("km2a_phi",&km2a_phi);
		LHAASOEventTree01[ifile]->SetBranchAddress("km2a_theta",&km2a_theta);

		int Nwfctaevts = LHAASOEventTree01[ifile]->GetEntries();
		printf("	tel01 events: %d\n",Nwfctaevts);

		for(i=0;i<Nwfctaevts;i++)
		{
			LHAASOEventTree01[ifile]->GetEntry(i);

			if(rabbitTime<TimeStart-timeside || rabbitTime>=TimeEnd+timeside){continue;}

			ievt_selected++;
			wfcta_time = (rabbitTime-TimeStart)*1000000000LL + rabbittime*20;
			wfcta_ievent = i+ifile*0.01+0.00001;
			tel01event.event_alltime = wfcta_time;
			tel01event.event_ievt = wfcta_ievent;
			tel01events.push_back(tel01event);
		}
		printf("	nevt ifile:%d tel01( selected/all ): %d/%d\n",ifile+1,ievt_selected,Nwfctaevts);
		ifile++;
	}
	printf("	nevt tel01( all selected ): %d\n",tel01events.size());
	sort(tel01events.begin(),tel01events.end(),comp);
	fclose(fp);
	cout<<"tel01 read time:"<<time(0)<<endl<<endl;


	//////////////////////////////////////////////////
	//		match events			//
	//////////////////////////////////////////////////
	setWFCTAEvent(tel01events,LHAASOEventTree01);
	/*
	for(int ii=0;ii<tel01events.size();ii++)
	{
		ievent = int(tel01events.at(ii).event_ievt);
		ifile = int((tel01events.at(ii).event_ievt-ievent)*100);
		LHAASOEventTree01[ifile]->GetEntry(ievent);
		printf("merge tel01 event:%.2lf %d %d   %d %lld %.0lf\n",tel01events.at(ii).event_ievt,ifile,ievent,iTel,rabbitTime,rabbittime);
	}
	*/

	int allmatchedevents=0;
	printf("allmatchedevents:%d\n",allmatchedevents);
	cout<<"match time:"<<time(0)<<endl<<endl;


	return 0;
}

void slaCldj ( int iy, int im, int id, double *djm, int *j )
{
	long iyL, imL;
	/* Month lengths in days */
	static int mtab[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	/* Validate year */
	if ( iy < -4699 ) { *j = 1; return; }
	/* Validate month */
	if ( ( im < 1 ) || ( im > 12 ) ) { *j = 2; return; }
	/* Allow for leap year */
	mtab[1] = ( ( ( iy % 4 ) == 0 ) &&
			( ( ( iy % 100 ) != 0 ) || ( ( iy % 400 ) == 0 ) ) ) ?
		29 : 28;
	/* Validate day */
	*j = ( id < 1 || id > mtab[im-1] ) ? 3 : 0;
	/* Lengthen year and month numbers to avoid overflow */
	iyL = (long) iy;
	imL = (long) im;
	/* Perform the conversion */
	*djm = (double)
		( ( 1461L * ( iyL - ( 12L - imL ) / 10L + 4712L ) ) / 4L
		  + ( 306L * ( ( imL + 9L ) % 12L ) + 5L ) / 10L
		  - ( 3L * ( ( iyL - ( 12L - imL ) / 10L + 4900L ) / 100L ) ) / 4L
		  + (long) id - 2399904L );
}

void setWFCTAEvent(const vector<wfctatime> &televents, TTree **lhTree)
{
	int ievent,ifile;
	for(int ii=0;ii<televents.size();ii++)
	{
		ievent = int(televents.at(ii).event_ievt);
		ifile = int((televents.at(ii).event_ievt-ievent)*100);
		lhTree[ifile]->GetEntry(ievent);
		//printf("merge tel01 event:%.2lf %d %d\n",tel01events.at(ii).event_ievt,ifile,ievent);
		printf("merge tel01 event:%.2lf %d %d   %d %lld %.0lf\n",tel01events.at(ii).event_ievt,ifile,ievent,iTel,rabbitTime,rabbittime);
	}
}
