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
		A(int i) : id(i){	std::cout<<"A constructor: "<<this<<" id:"<<this->id<<std::endl;}
		~A(){	std::cout<<"A destructor: "<<this<<" id:"<<this->id<<std::endl;}

		static void* operator new(size_t size)
		{
			void* ptr = malloc(size);
			std::cout<<"A operator new: "<<ptr<<std::endl;
			return ptr;
		}
		static void operator delete(void *ptr)
		{
			std::cout<<"A operator delete: "<<ptr<<std::endl;
			free(ptr);
		}
};

int main()
{
	std::cout<<"size(A): "<<sizeof(A)<<std::endl<<std::endl;
	A *pA1 = new A(1);
	delete pA1;
	std::cout<<std::endl;
	A *pA2 = ::new A(1);
	::delete pA2;
	return 0;
}
