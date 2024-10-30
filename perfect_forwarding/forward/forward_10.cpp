#include <type_traits>
#include <iostream>
#include <string>


template <typename T>
void foo(T&& r)
{
	if constexpr (std::is_lvalue_reference_v<T>) {
		std::cout << "call with an L value\n";
	}
	else {
		std::cout << "call with an R value\n";
	}
}

int main()
{
	auto fn = [](auto&& arg) {
		foo(std::forward<decltype(arg)>(arg));
	};

	std::string name{ "necati ergin" };
	fn(name);
	fn(std::move(name));
	fn(std::string{ "ahmet aksoy" });

}
