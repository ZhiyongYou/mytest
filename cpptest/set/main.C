#include <iostream>
#include <stdio.h>
#include <set>

int main()
{
	int numList[6]={1,4,2,3,3,3};
	std::set<int> numSet;
	for(int i=0;i<6;i++)
	{
		numSet.insert(numList[i]);
	}
	for(std::set<int>::iterator it=numSet.begin();it!=numSet.end();it++)
	{
		printf("%d\n",*it);
	}
	printf("setsize:%d\n",numSet.size());
	return 0;
}
