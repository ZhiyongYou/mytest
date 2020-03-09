#include <iostream>

inline void* operator new(size_t size)
{
	std::cout<<"my operator new:"<<std::endl;
	return malloc(size);
}
inline void operator delete(void *ptr)
{
	std::cout<<"my operator delete:"<<std::endl;
	free(ptr);
}

class A
{
	protected:
		int ic;
	public:
		int id;
		int iid;
		A(int i) : id(i)
		{
			std::cout<<"A constructor: "<<this<<std::endl;
		}
		~A()
		{
			std::cout<<"A destructor: "<<this<<std::endl;
		}
};

int main()
{
	std::cout <<"size(A): "<<sizeof(A)<< std::endl;
	A *pA = new A(1);
	
	delete pA;
	return 0;
}
