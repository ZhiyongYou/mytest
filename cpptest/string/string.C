#include <stdio.h>
#include <iostream>
//#include <cstring>  //include method of c string: strlen(), strcpy() ...
#include <string>  //include string class

int main()
{
	std::string word = "word";
	std::cout<<word<<std::endl;
	printf("%s\n",word.c_str());
}
