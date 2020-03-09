#include <iostream>

class A
{
	protected:
		int ic;
	public:
		int id;
		int iid;
		A(int i) : id(i)
		{
			std::cout<<"A constructor"<<this<<std::endl;
		}
		~A()
		{
			std::cout<<"A destructor"<<this<<std::endl;
		}
};

int main()
{
	int *pI = new int[6];
	std::cout << pI <<" size(pI): "<<sizeof(pI)<< std::endl;
	int aI[6];
	std::cout << aI <<" size(aI): "<<sizeof(aI)<< std::endl;
	delete [] pI;
	

	std::cout <<"size(A): "<<sizeof(A)<< std::endl;



	A *pA = new A(1);
	A a(2);
	
	std::cout << pA << std::endl;
	std::cout << sizeof(pA) << " " <<sizeof(a)<<" "<<a.id<<" "<< pA->id << std::endl;
	// pA->A::A(3); cannot call constructor ‘A::A’ directly
	pA->~A();
	std::cout << pA->id << std::endl;
	delete pA;
	std::cout << pA->id << std::endl;
	return 0;
}
