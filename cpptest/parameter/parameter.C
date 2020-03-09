#include <stdio.h>
#include <iostream>

int shifgvalue(int val, int shift=10);

int main()
{
	int val=0;
	printf("raw: %d\n",val);
	printf("default(10) shitf: %d\n",shifgvalue(val));
	printf("1 shitf: %d\n",shifgvalue(val,1));
}

int shifgvalue(int val, int shift)
{
	return val+shift;
}
