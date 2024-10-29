// named return value optimization
// it is not mandatory

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


Nec func()
{
	Nec x;
	//use x
	return x;
}

int main()
{
	Nec m{ func() };
}
