#include <iostream>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c[10];
	int test=0;
	strcpy(c, "empty");
	if(strcmp(c, "empty") == 0)
		test=1;
	printf("test:%d  c:%s\n",test,c);
	return 0;
}
