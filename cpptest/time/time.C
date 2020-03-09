#include <time.h>
#include <iostream>
using namespace std;

int main()
{
	clock_t startTime,endTime;
	startTime = clock();
	for (int i = 0; i < 1000000000; i++)
	{
		i++;
	}
	endTime = clock();
	cout<<CLOCKS_PER_SEC<<endl;
	cout << "Totle Time : " <<(double)(endTime - startTime)/(CLOCKS_PER_SEC)*1000 << "ms" << endl;
	return 0;
}
