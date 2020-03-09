#include <iostream>
#include <stdio.h>

void swap(int &a, int &b)
{
	int s_swap = b;
	b = a;
	a = s_swap;
}

int main()
{
	int a = 3, b = 5;
	printf("%d %d\n",a,b);
	swap(a,b);
	printf("%d %d\n",a,b);
	double c = 3.5, d = 5.5;
	printf("%lf %lf\n",c,d);
	swap(c,d);
	printf("%lf %lf\n",c,d);

}
