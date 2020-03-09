#include <iostream>
#include <stdio.h>

long long factorial(long long i)
{
	if(i==1){	return 1;}
	else	{	return i * factorial(i-1);}
}

int main(int argc, char **argv)
{
	long long fac;
	fac = factorial(atoll(argv[1]));
	long long *f = new long long;
	*f = fac;
	std::cout<<f<<std::endl;
	std::cout<<*f<<std::endl;
	printf("%d\n",fac);
}

