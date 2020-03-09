#include <iostream>
#include <bitset>

void roundUp(int num, int base)
{
	int round_num;
	round_num = ((num) + base-1) & ~(base-1);
	std::cout<<round_num<<std::endl;
}
