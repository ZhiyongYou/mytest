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
	for(int i=0;i<10000000;i++){
		try {
			if( n == 0)
				throw n; //抛出int类型异常
			else
				cout << m / n << endl;
		}
		catch(double d) {
		}
	}
	time_t end = time(0);
	cout << "end:" << end << endl;
	cout << "alltime:" << end - begin << endl;
	return 0;
}
