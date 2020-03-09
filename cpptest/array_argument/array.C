#include <stdio.h>
#include <iostream>
#include <typeinfo>

void setArray(double *arr, double *ARR, double &v_a, double v_b)
{
	for(int i=0;i<10;i++)
	{
		*(arr+i) = i*10;
		ARR[i] = i*100;
	}
	v_a = 6;
	v_b = 6;
	std::cout<<"type(ar:)"<<typeid(arr).name()<<"      type(AR):"<<typeid(ARR).name()<<"      type(valueA):"<<typeid(v_a).name()<<"   type(valueB):"<<typeid(v_b).name()<<std::endl;
}

void outputArray(double *arr, double *ARR, double v_a, double v_b)
{
	std::cout<<"type(ar:)"<<typeid(arr).name()<<"      type(AR):"<<typeid(ARR).name()<<"      type(valueA):"<<typeid(v_a).name()<<"   type(valueB):"<<typeid(v_b).name()<<std::endl;
	printf("---------------------------------------------------------------------------\n");
	printf("valueA:%6.2lf  valueB:%6.2lf\n",v_a,v_b);
	printf("---------------------------------------------------------------------------\n");
	for(int i=0;i<10;i++)
	{
		printf("arr[%d]:%6.2lf  ARR[%d]:%6.2lf\n",i,*(arr+i),i,ARR[i]);
	}
}

int main()
{
	double valueA=0;
	double valueB=0;
	double ar[10]={0};
	double AR[10]={0};
	printf("===========================================================================\n");
	setArray(ar,AR,valueA,valueB);
	printf("===========================================================================\n");
	std::cout<<"type(ar:)"<<typeid(ar).name()<<"   type(AR):"<<typeid(AR).name()<<"   type(valueA):"<<typeid(valueA).name()<<"   type(valueB):"<<typeid(valueB).name()<<std::endl;
	printf("===========================================================================\n");
	outputArray(ar,AR,valueA,valueB);
	printf("===========================================================================\n");
}
