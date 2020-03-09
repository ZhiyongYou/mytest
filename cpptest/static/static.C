#include <iostream>

class Acount
{
	public:
		static double m_rate;
		static void set_rate(const double& x);

	private:
		double storage;
};

double Acount::m_rate = 8;

inline
void Acount::set_rate(const double& x)
{
	m_rate = x;
}

int main()
{
	double rate = 9;
	std::cout << Acount::m_rate << std::endl;
	Acount::set_rate(10);
	std::cout << Acount::m_rate << std::endl;
	Acount a;
	a.set_rate(rate);
	std::cout << Acount::m_rate << std::endl;
}
