template <typename T>
struct Valcat {
	constexpr static const char* p = "PR value";
};

template <typename T>
struct Valcat<T&> {
	constexpr static const char* p = "L value";
};

template <typename T>
struct Valcat<T&&> {
	constexpr static const char* p = "X value";
};

#include <iostream>

#define  pvcat(e)       std::cout << "value category of : '" << #e << "' is " << Valcat<decltype((e))>::p << '\n'
