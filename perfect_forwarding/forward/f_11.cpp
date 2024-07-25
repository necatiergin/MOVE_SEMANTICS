#include <type_traits>
#include <iostream>

void bar(std::string&)
{
	std::cout << "bar(string &)\n";
}

void bar(const std::string&)
{
	std::cout << "bar(const string &)\n";
}
void bar(std::string&&)
{
	std::cout << "bar(string &&)\n";
}

void bar(const std::string&&)
{
	std::cout << "bar(const string &&)\n";
}

template <typename T>
requires (!std::is_lvalue_reference_v<T>)
void foo(T&& arg)
{
	//bar(std::forward<T>(arg));
	bar(std::move(arg));
}

int main()
{
	std::string str{ "L Value" };
	const std::string cs{ "const L Value" };

	//foo(str); //error
	//foo(cs); //error
	foo(std::move(str)); //valid
	foo(std::move(cs)); //valid
}
