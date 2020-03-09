#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void);

int main(int argc,char* argv[])
{
	long thread_count = strtol(argv[1],NULL,10);
	//获取线程数
	std::cout<<"out------------------->"<<omp_in_parallel()<<std::endl;
#   pragma omp parallel num_threads(thread_count)
	Hello();
	return 0;
}

void Hello(void)
{
	int my_rank = omp_get_thread_num();
	//获取线程编号
	int thread_count = omp_get_num_threads();
	//获取线程数
	int max_thread_count = omp_get_max_threads();
	printf("Hello World from thread %d of %d | %d\n",my_rank,thread_count,max_thread_count);
}
