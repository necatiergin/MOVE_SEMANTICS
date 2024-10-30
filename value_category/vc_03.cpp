#include <iostream>

class Myclass {
	//
};


void foo(Myclass&)
{
	std::cout << "foo(Myclass&)\n";
}

void foo(const Myclass&)
{
	std::cout << "foo(const Myclass&)\n";
}

void foo(Myclass &&)
{
	std::cout << "foo(Myclass&&)\n";
}

Myclass g;
Myclass bar() { return g; }
Myclass& baz() { return g; }

int main()
{
	Myclass x;
	const Myclass cx;

	foo(x);
	foo(cx);
	foo(std::move(x));
	foo(Myclass{});
	foo(bar());
	foo(baz());
}
