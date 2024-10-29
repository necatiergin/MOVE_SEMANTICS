#include <iostream>

class Myclass {
public:
	Myclass()
	{
		std::cout << "default ctor\n";
	}

	~Myclass()
	{
		std::cout << "destructor\n";
	}

	Myclass(int)
	{
		std::cout << "Myclass(int)\n";
	}

	Myclass(const Myclass&)
	{
		std::cout << "copy ctor\n";
	}

	Myclass(Myclass&&)
	{
		std::cout << "move ctor\n";
	}
	//...
};


Myclass foo()
{
	Myclass x(12);

	return std::move(x);
}


int main()
{
	auto y = foo();
	// ...
	
}
