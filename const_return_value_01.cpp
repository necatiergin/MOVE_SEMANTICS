#include <iostream>

class Nec {
public:
	Nec() = default;
	Nec(const Nec&) = default;
	Nec(Nec&&) = default;
	Nec& operator=(const Nec&)
	{
		std::cout << "copy assignment\n";
		return *this;
	}

	Nec& operator=(Nec&&)
	{
		std::cout << "move assignment\n";
		return *this;
	}
};


//const return value blocks move semantics
const Nec foo()
{
	Nec x;

	return x;
}

Nec bar()
{
	Nec x;

	return x;
}

int main()
{
	Nec x;
	//..

	x = foo();
	x = bar();
}
