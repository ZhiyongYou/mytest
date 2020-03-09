#include <iostream>
#include <stdio.h>
#include <vector>

void vec_set(std::vector<int> &vec)
{
	for(int i=0;i<10;i++){
		vec.push_back(i*10);
	}
}

void vec_out(std::vector<int> vec)
{
	for(int i=0;i<10;i++){
		std::cout<<i<<": "<<vec.at(i)<<std::endl;
	}
}

int main()
{
	std::vector<int>* vec = new std::vector<int>();
	vec_set(*vec);
	vec->at(0) = 11;
	vec->at(vec->size()-1) = 100;
	vec_out(*vec);
	printf("test\n");
	return 0;
}
