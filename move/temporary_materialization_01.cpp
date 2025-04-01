#include <iostream>

class Nec {
public:
	Nec()
	{
		std::cout << "default ctor\n";
	}

	Nec(const Nec&)
	{
		std::cout << "copy ctor\n";
	}

	Nec(Nec&&)noexcept
	{
		std::cout << "move ctor\n";
	}
};

int main()
{
	Nec&& r = Nec{};
	//temporary materialization default ctor called
	Nec x = r; //copy ctor , r is lvalue expression
	Nec y = std::move(r); //move ctor std::move(r) is r value
}
