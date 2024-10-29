#include <iostream>

class Nec {
public:
	Nec()
	{
		static int count{};
		std::cout << "default ctor called " << ++count << " times\n";
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


void func(Nec x)
{
	//...
}

Nec foo()
{
	return Nec{}; //rvo mandatory
}

int main()
{
	Nec x = Nec{};
	//Nec y = Nec{ Nec{ Nec{} } };
	//func(Nec{});
	//Nec z{ foo() };
	//Nec t{ Nec{foo()} };

}
