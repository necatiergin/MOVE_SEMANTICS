#include <type_traits>
#include <iostream>

template <typename T>
void func(T&&)
{
	if constexpr (std::is_integral_v<std::remove_reference_t<T>>) {
		std::cout << "integral type\n";
	}
	else {
		std::cout << "not integral type\n";
	}
}

int main()
{
	int x = 10;

	func(10);
	func(x);
}
