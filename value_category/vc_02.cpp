#include <iostream>
#include <type_traits>

#define exp(x)       decltype((x))

int main()
{
	int x{};

	if constexpr (std::is_lvalue_reference_v<exp(x + 5)>)
		std::cout << "lvalue expression\n";
	else if constexpr (std::is_rvalue_reference_v<exp(x + 5)>)
		std::cout << "xvalue expression\n";
	else
		std::cout << "prvalue expression\n";
}
