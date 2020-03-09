#include <stdio.h>
#include <iostream>

void set(int *val)
{
	*val = 101;
}

int main()
{
	int out=100;
	int j;
	for(int i=0;i<3;i++)
	{
		switch(i)
		{
			case 1:
				j=2;
				int val;
				printf("%d %d %d\n",out,j,val);
				break;
			case 2:
				set(&val);
				printf("%d %d %d\n",out,j,val);
				break;
			default :
				break;
		}
	}
}
