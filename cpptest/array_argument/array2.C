#include <stdio.h>
#include <iostream>
#include <typeinfo>

void setArray(double *arr)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++){
			*(arr+i*10+j) = i*10+j;
		}
	}
}

void outputArray(double *arr)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++){
			printf("arr[%d][%d]:%6.2lf\n",i,j,*(arr+i*10+j));
		}
	}
}

int main()
{
	double ar[6][10];
	printf("===========================================================================\n");
	setArray((double *)ar);
	outputArray((double *)ar);
	printf("===========================================================================\n");
}
