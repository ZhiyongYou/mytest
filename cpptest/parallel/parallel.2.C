#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//一个简单的耗时任务
double Sum0(double* data,long data_count);

int main()
{
	long data_count=200000;
	double* data=new double[data_count];
	long i;

	//初始化测试数据
	for (i=0;i<data_count;++i)
		data[i]=(double)(rand()*(1.0/RAND_MAX));

	const long test_count=200*2;//为了能够测量出代码执行的时间，让函数执行多次
	double sumresult=0;
	double runtime=(double)clock();
	for( i=0; i<test_count; ++i ) 
	{
		sumresult+=Sum0(data,data_count);
	}
	runtime=((double)clock()-runtime)/CLOCKS_PER_SEC;
	printf ("< Sum0 >  ");
	printf ("  最后结果     = %10.4f  ",sumresult);
	printf ("  执行时间(秒) = %f  \n",runtime);

	delete [] data;
	return 0;
}


double Sum0(double* data,long data_count)
{
	double result=0;
#pragma omp parallel for schedule(static) reduction(+: result)
	for (long i=0;i<data_count;++i)
	{
		data[i]=(double)sin(cos(data[i]));
		result+=data[i];
	}
	return  result;
}
