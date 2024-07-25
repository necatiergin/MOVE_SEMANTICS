// std::move_if_noexcept

#include <utility>
#include <iostream>

struct A {
	A() = default;

	//A(A&&)
	A(A&&)noexcept
	{
		std::cout << "move ctor\n";
	}

	A(const A&)
	{
		std::cout << "copy ctor\n";
	}
};


int main()
{
	A ax;

	A bx(std::move_if_noexcept(ax));
}
