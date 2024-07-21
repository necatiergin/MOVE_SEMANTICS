#include <utility>

template<typename T>
void callFoo(T&& arg) 
{
	foo(std::forward<T>(arg));
}

// C++20
void callFoo(auto&& arg) 
{
	foo(std::forward<decltype(arg)>(arg));
}
