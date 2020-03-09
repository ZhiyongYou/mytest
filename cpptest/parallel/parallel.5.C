#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <omp.h>
#include <string>
#include <cstring>

int main(int argc,char* argv[])
{
	std::string outfile[6];
#pragma omp parallel for schedule(static, 1)
		for (int i = 0; i < 6; i++)
		{
			outfile[i] = "outfile/out" + std::to_string(i);

			//FILE *outfilelist=fopen(,"w");
			printf("i = %d, I am Thread %d %s\n", i, omp_get_thread_num(), outfile[i].c_str());
		}
}
