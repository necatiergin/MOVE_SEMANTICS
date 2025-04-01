// pessimistic_move

#include <iostream>

struct A {
	A()
	{
		std::cout << "default ctor\n";
	}

	A(const A&)
	{
		std::cout << "copy ctor\n";
	}

	A(A&&)
	{
		std::cout << "move  ctor\n";
	}
};

A func()
{
	A ax;

	return std::move(ax); //don't do this
	//return ax; //do this
}

A foo()
{
	return std::move(A{}); //don't do this
	//return A{}; //do this
}

A create()
{
	A ax;

	//
	return ax;
}

int main()
{
	A x{ foo() };
	A y{ func() };
	A z{ std::move(create())}; //don't do this
}
