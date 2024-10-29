#include <iostream>

class Nec {
public:
	Nec()
	{
		std::cout << "default ctor called\n";
	}


	Nec(const Nec&)
	{
		std::cout << "copy ctor\n";
	}

	Nec(Nec&&)
	{
		std::cout << "move ctor\n";
	}
};


Nec func(Nec x);

int main()
{
	Nec mx; //default ctor
	Nec my{ func(mx) }; //
}

//returns parameter no NRVO

Nec func(Nec x)
{
	//use x;
	return x;
}
