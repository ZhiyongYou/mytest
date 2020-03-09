#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctime>
using namespace std;

int main(int argc, char *argv[])
{
	time_t begin = time(0);
	cout << "begin:" << begin << endl;
	double m ,n;
	m = atof(argv[1]);
	n = atof(argv[2]);
	int dividezero = 0;
	for(int i=0;i<1000000000;i++){
		if( n == 0)
			dividezero = 1;				
		else
			cout << m / n << endl;
		if(dividezero==1){

		}
	}
	time_t end = time(0);
	cout << "end:" << end << endl;
	cout << "alltime:" << end - begin<< endl;
	return 0;
}
