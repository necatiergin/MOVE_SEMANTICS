#include <type_traits>
#include <iostream>

class Nec {};

template<typename T>
void foo(T&&)
{
	if constexpr (std::is_lvalue_reference_v<T>) {
		std::cout << "argument is L value\n";
	}
	else {
		std::cout << "argument is R value\n";
	}
}

int main()
{
	Nec nec;
	const Nec cnec;

	foo(nec);
	foo(cnec);
	foo(std::move(nec));
	foo(Nec{});
	foo(std::move(cnec));
}
