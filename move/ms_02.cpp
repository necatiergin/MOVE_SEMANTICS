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

	Myclass& operator=(const Myclass&)
	{
		std::cout << "copy assignment\n";
		return *this;
	}

	Myclass& operator=(Myclass&&)
	{
		std::cout << "move assignment\n";
		return *this;
	}
};

Myclass func(Myclass m)
{
	//code
	return m;
}

int main()
{
	auto m2 = func(13); //mandatory copy elision + move assignment
}
