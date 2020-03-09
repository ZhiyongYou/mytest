//use g++ -o swap.exe swap.test to compile
//create executive file
#include <stdio.h>
#include <iostream>
int main()
{
	int a=5;
	int b=6;
	printf("a:%d b:%d\n",a,b);
	std::swap(a,b);
	printf("a:%d b:%d\n",a,b);
	int *AddresA =  std::addressof(a);
	//std::cout<<AddresA<<std::endl;
	printf("addresOfa:%p\n",std::addressof(a));
}
