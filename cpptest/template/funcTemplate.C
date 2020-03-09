#include <iostream>

class Stone
{
	public:
		Stone(double h=0, double w=0, double we=0);
		~Stone();
		bool operator< (const Stone& rhs) const;
		double get_weight() const {return _weight;};

	private:
		double _high;
		double _width;
		double _weight;
};

Stone::Stone(double h, double w, double we) : _high(h), _width(w), _weight(we)
{
}

Stone::~Stone()
{
}

bool Stone::operator< (const Stone& rhs) const
{
	std::cout << "Stone '<' operator" << std::endl;
	return this->_weight < rhs._weight;
}

template <typename T>
inline
const T& min(const T& a, const T& b)
{
	return b < a ? b : a;
}

int main()
{
	Stone a1(1,1,10), a2(0.5,0.5,2), a3;
	a3 = min(a1,a2);
	std::cout << a3.get_weight() << std::endl;
}
