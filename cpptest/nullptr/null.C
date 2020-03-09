#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <exception>

int main()
{
	int b = 10;
	int *a = nullptr;
	a = &b;
	std::cout<<"type(a):"<<typeid(a).name()<<std::endl;
	printf("address(a):%d\n",a);
	std::cout<<"address(a):"<<a<<std::endl;

	std::cout<<"type(*a):"<<typeid(*a).name()<<std::endl;
	printf("value(a):%d\n",*a);
	std::cout<<"value(a):"<<*a<<std::endl;

	std::cout<<"-------------------------------------------"<<std::endl;

	int *c = nullptr;
	std::cout<<"type(c):"<<typeid(c).name()<<std::endl;
	printf("address(c):%d\n",c);
	std::cout<<"address(c):"<<c<<std::endl;

	std::string str = "http://c.biancheng.net";
	try
	{
		//char ch1 = str[100];  //下标越界，ch1为垃圾值
		//std::cout<<ch1<<std::endl;
		char ch2 = str.at(100);  //下标越界，抛出异常
		std::cout<<ch2<<std::endl;
		std::cout<<"type(*c):"<<typeid(*c).name()<<std::endl;

		//printf("value(c):%d\n",*c);//*c 错误不会抛出异常
		//std::cout<<"value(c):"<<*c<<std::endl;
	}
	catch(...)
	{
		std::cout<<"can not use '*a'"<<std::endl;
	}


	return 0;
}
