#include <iostream>
#include <bitset>

void bin(int num)
{
	std::cout<<bitset<sizeof(int)*8>(num)<<std::endl;
}
