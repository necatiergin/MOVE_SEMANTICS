//without perfect forwarding

#include <iostream>

//without perfect forwarding

class Nec {

};

void foo(Nec &)
{
	std::cout << "foo(Nec &)\n";
}

void foo(const Nec&)
{
	std::cout << "foo(const Nec &)\n";
}

void foo(Nec&&)
{
	std::cout << "foo(Nec &&)\n";
}

void call_foo(Nec& n)
{
	foo(n);
}

void call_foo(const Nec& n)
{
	foo(n);
}

void call_foo(Nec&& n)
{
	foo(std::move(n));
}

int main()
{
	Nec n;
	const Nec cn;

	foo(n); call_foo(n);
	std::cout << "------------------------------------------\n";
	foo(cn); call_foo(cn);
	std::cout << "------------------------------------------\n";
	foo(Nec{}); call_foo(Nec{});
	std::cout << "------------------------------------------\n";
	foo(std::move(n)); call_foo(std::move(n));
	std::cout << "------------------------------------------\n";
}
