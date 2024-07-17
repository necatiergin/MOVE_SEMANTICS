#include <type_traits>
#include <iostream>

int main()
{
	constexpr auto b1 = std::is_const_v<int>; // false
	constexpr auto b2 = std::is_const_v<const int>; // true
	constexpr auto b3 = std::is_const_v<const int&>; // false
	constexpr auto b4 = std::is_const_v<std::remove_reference_t<const int&>>; // true
}
