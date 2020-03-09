#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc,char* argv[])
{
#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < 6; i++)
			printf("i = %d, I am Thread %d\n", i, omp_get_thread_num());
#pragma omp master
		{
			//这里的代码由主线程执行
			printf("I am Thread %d\n", omp_get_thread_num());
		}
#pragma omp for
		for (int i = 0; i < 6; i++)
			printf("i = %d, I am Thread %d\n", i, omp_get_thread_num());
	}
}
