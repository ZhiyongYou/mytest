#include <stdio.h>
#include <iostream>
#include <string>
#include "TFile.h"
#include "TTree.h"

using namespace std;

int main(int argc, char** argv)
{
	string filename = argv[1];
	int posES =  filename.find("ES.", 0);
	int posroot =  filename.find(".root", 0);
	int file_name_len = posroot-posES+5;
	string b_filename = filename.substr(posES,file_name_len);
	//read event files
	char Name1[300]="root://eos01.ihep.ac.cn/";
	char Name2[300];
	strcpy(Name2,Name1);
	strcat(Name2,argv[1]);
	TFile *file_event = TFile::Open(Name2);
	if(!file_event)
	{
		printf("first check: %s dose not exist %s\n",argv[1]);
		return 1;
	}
	if(file_event->IsZombie()||file_event->GetEND()<50)
	{
		printf("second check: %s is null file\n",b_filename.c_str());
		file_event->Close();
		delete file_event;
		return 1;
	}
	TTree *Eventchain = (TTree *)file_event->Get("trec");
	if(Eventchain==nullptr)
	{
		printf("third check: %s is null file\n",b_filename.c_str());
		file_event->Close();
		delete file_event;
		delete Eventchain;
		return 1;
	}
	printf("%d\n",Eventchain->GetEntries());
}
