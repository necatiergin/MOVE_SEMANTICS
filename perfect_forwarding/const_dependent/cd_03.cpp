#include <iostream>

template <typename T>
void f(T&&)
{
	if constexpr (std::is_const_v<std::remove_reference_t<T>>) {
		std::cout << "code for const values\n";
	}
	else {
		std::cout << "code for non-const values\n";
	}
}

class Myclass {};

int main()
{
	Myclass m{};
	const Myclass cm{};
	const Myclass& cr{ m };
	const Myclass& r{ m };

	f(m);
	f(cm);
	f(m);
	f(cr);
	f(std::move(m));
	f(std::move(cm));
}
