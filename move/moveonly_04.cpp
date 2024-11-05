#include <iostream>

class MoveOnly {
public:
	MoveOnly()
	{
		std::cout << "default ctor\n";
	}
	MoveOnly(MoveOnly&&)
	{
		std::cout << "move ctor\n";
	}
	
	MoveOnly& operator=(MoveOnly&&)
	{
		std::cout << "move assignment\n";
		return *this;
	}

	//...	
};

MoveOnly foo(MoveOnly m)
{
	//...
	return m;
}

int main()
{
	MoveOnly x;

	x = foo(std::move(x));
}
