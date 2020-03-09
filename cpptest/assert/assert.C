#include <stdio.h>
#include <iostream>

#define NDEBUG
#include <assert.h>

int main(int argc, char** argv)
{
	for(int i=0;i<100;i++)
	{
		assert(i<10);
		printf("%d\n",i);
	}
	return 0;
}
