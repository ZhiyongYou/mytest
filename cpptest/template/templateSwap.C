#include <iostream>
#include <stdio.h>
#include <string>

template<typename T>
void swap(T &a, T &b)
{
	T s_swap = b;
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

	std::string s_a = "string_a";
	std::string s_b = "string_b";
	std::cout<<s_a<<" "<<s_b<<std::endl;
	swap(s_a,s_b);
	std::cout<<s_a<<" "<<s_b<<std::endl;

}
