#include <iostream>
#include <type_traits>

class Nec {};

template<typename T>
void foo(const char *p,  T&&)
{
	if constexpr (std::is_lvalue_reference_v<T>) {
		std::cout << "argument is '" << p << "'" << " has come here and it is L value\n";
	}
	else {
		std::cout << "argument is '" << p << "'" << " has come here and it is R value\n";
	}
}

int main()
{
	Nec n;
	const Nec cn;

	foo("n", n);
	foo("cn", n);
	foo("std::move(n)", std::move(n));
	foo("Nec{}", Nec{});
}
