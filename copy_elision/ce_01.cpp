#include <iostream>

struct A {
	A()
	{
		std::cout << "default ctor this = " << this << '\n';
	}

	A(const A&) = delete;
	//no move ctor
};

void foo(A) { }

A bar()
{
	return A{};
}

int main()
{
	A ax = A{};  //mandatory copy elision
	foo(A{});   //mandatory copy elision
	A ay = bar();  //mandatory copy elision
}
