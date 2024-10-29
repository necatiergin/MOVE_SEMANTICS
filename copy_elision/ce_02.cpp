#include <iostream>

struct A {
	A(int x)
	{
		std::cout << "A(int x) x = " << x << '\n';
	}

	A(const A&) = delete;
	A(A&&) = delete;
};

void func(A) { }

A foo()
{
	return A{ 3 };
}

int main()
{
	A ax = A{ 1 }; //mandatory copy elision
	func(A{ 2 }); //mandatory copy elision
	A ay = foo(); //mandatory copy elision
}
