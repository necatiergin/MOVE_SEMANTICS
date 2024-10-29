//mandatory elision example

#include <iostream>

class Nec {
public:
	Nec(const char*)
	{
		std::cout << "Nec(const char *)\n";
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


Nec foo()
{
	return "necati";
}

Nec bar()
{
	return foo();
}

int main()
{
	auto x = bar();  //Nec(const char *)
}
