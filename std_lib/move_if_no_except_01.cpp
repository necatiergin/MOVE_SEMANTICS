//move_if_no_except in utility header

#include <iostream>


struct A {
	A() = default;

	A(A&&)noexcept
	{
		std::cout << "move ctor\n";
	}

	A(const A&)noexcept
	{
		std::cout << "copy ctor\n";
	}
};


int main()
{
	A ax;

	A bx(std::move_if_noexcept(ax)); 
}
