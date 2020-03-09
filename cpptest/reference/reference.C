#include <iostream>
#include <stdio.h>
#include <vector>

int& add(int &a, int &b)
{
	a += b;
	return a;
}
int& Add(int a, int b)
{
	int A;
	A = a + b;
	return a;
}

int main()
{
	int a=1, b=2;
	int c = 0;
	c = add(a,b);
	int C = 0;
	//C = Add(a,b); // the return object deads when Add() finished, compile: warning, run: Segmentation fault (core dumped)
	printf("%d %d\n",c,C);

	int i = 6;
	int& ir = i;
	printf("i:%d\n",i);
	printf("ir:%d\n",ir);

	ir = 7;
	printf("i:%d\n",i);
	printf("ir:%d\n",ir);

	return 0;
}
