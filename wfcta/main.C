#include <iostream>
#include <stdio.h>
#include "OnlineProcess.h"

int main()
{
	double Temp[1024]={0};
	for(int iloop=0;iloop<10;iloop++){
		printf("loop%d\n",iloop);
		OnlineProcess *onlineMonitor = new OnlineProcess();
		for(int i=0;i<1024;i++)
		{
			int ichannel=i+1;
			if((ichannel%128)%4==0){
				Temp[i] = i+iloop*10+100;
			}
			else{
				Temp[i] = i+iloop*10;
			}
		}
		onlineMonitor->SetHVTempPar(Temp);
		onlineMonitor->CalcNextHV();
	}
}

