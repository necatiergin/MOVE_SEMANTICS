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


void bar(Myclass)
{
	//...
}

int main()
{
	bar(Myclass {});
	//bar(std::move(Myclass{}));
	
}
