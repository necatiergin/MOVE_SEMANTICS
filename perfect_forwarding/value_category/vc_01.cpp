template<typename T>
struct ValCat {
	static constexpr const char* p = "PR value";
};

template <typename T>
struct ValCat <T&> {
	static constexpr const char* p = "L value";
};

template <typename T>
struct ValCat <T&&> {
	static constexpr const char* p = "X value";
};

#include <iostream>

#define  print_val_cat(expr)   std::cout << "value category of expr '" #expr "' is : " << ValCat<decltype((expr))>::p << '\n'
