#include <iostream>

class Myclass {
public:
	Myclass()
	{
		std::cout << "default ctor called\n";
	}


	Myclass(const Myclass&)
	{
		std::cout << "copy ctor\n";
	}

	Myclass(Myclass&&)
	{
		std::cout << "move ctor\n";
	}
};


//no return value optimization
//multiple return statements

Myclass func(bool b)
{
	Myclass x, y;

	if (b)
		return x;

	return y;
}

int main()
{
	Myclass mx{ func(10 > 5) };
	//Myclass my{ func(5 > 10)};
}
