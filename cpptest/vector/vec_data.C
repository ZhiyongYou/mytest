#include <iostream>
#include <stdio.h>
#include <vector>

int main()
{
	std::vector<int> vec;
	for(int i=0;i<10;i++){
		vec.push_back(i);
	}
	int *p_v = vec.data();
	for(int i=0;i<10;i++){
		printf("%d ",p_v[i]);
	}
	printf("\n");
	return 0;
}
