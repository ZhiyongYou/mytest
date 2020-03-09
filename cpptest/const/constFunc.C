#include <iostream>
#include <stdio.h>

class Stone
{
	private:
		double mass;
		double len;
		double wid;
		double high;
	public:
		Stone(){};
		Stone(double m);
		~Stone();

		void setMass(double Mass);
		void printMass() const;
};
Stone::Stone(double m):mass(m)
{
};
Stone::~Stone()
{
};
void Stone::setMass(double Mass)
{
	mass = Mass;
};
void Stone::printMass() const
{
	std::cout<<mass<<" kilogram"<<std::endl;
};

int main()
{
	Stone stone;
	stone.setMass(3.3);
	stone.printMass();

	const Stone stone1(5.5);
	stone1.printMass();

}
