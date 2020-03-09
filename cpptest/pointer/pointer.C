#include <iostream>
#include <stdio.h>

int val = 1;

void fu(int *p)
{
	*p = val;
}

void f(int *p)
{
	p = &val;
}

void func(int &p)
{
	p = val;
}

int main()
{
	int a = 2, b = 3, c = 4;
	int *pa;
	int *pc;
	pa = &a;
	pc = &c;
	std::cout<<*pc<<" "<<*pa<<" "<<b<<std::endl;
	fu(pc);
	f(pa);
	func(b);
	std::cout<<*pc<<" "<<*pa<<" "<<b<<std::endl;
	return 0;
}
