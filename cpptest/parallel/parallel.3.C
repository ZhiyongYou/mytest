#include<cstdlib>
#include<iostream>
#include<omp.h>

using namespace std;

void test()
{
	for (int i = 0; i < 80000; i++)
	{
	}
}

int main()
{
	float startTime = omp_get_wtime();


#pragma omp parallel for num_threads(1)
	for (int i = 0; i < 80000; i++){
		test();
	}
	float endTime = omp_get_wtime();
	printf("指定 1 个线程，执行时间: %f\n", endTime - startTime);
	startTime = endTime;
#pragma omp parallel for num_threads(2)
	for (int i = 0; i < 80000; i++){
		test();
	}
	endTime = omp_get_wtime();
	printf("指定 2 个线程，执行时间: %f\n", endTime - startTime);
	startTime = endTime;
#pragma omp parallel for num_threads(4)
	for (int i = 0; i < 80000; i++){
		test();
	}
	endTime = omp_get_wtime();
	printf("指定 4 个线程，执行时间: %f\n", endTime - startTime);
	startTime = endTime;
#pragma omp parallel for num_threads(8)
	for (int i = 0; i < 80000; i++){
		test();
	}
	endTime = omp_get_wtime();
	printf("指定 8 个线程，执行时间: %f\n", endTime - startTime);
	startTime = endTime;
#pragma omp parallel for num_threads(12)
	for (int i = 0; i < 80000; i++){
		test();
	}
	endTime = omp_get_wtime();
	printf("指定 12 个线程，执行时间: %f\n", endTime - startTime);
	startTime = endTime;
}
