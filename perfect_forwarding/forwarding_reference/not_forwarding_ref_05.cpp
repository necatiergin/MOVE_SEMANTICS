#include <iostream>
#include <string>

template <typename T>
void func(T&&) //forwarding reference parameter
{
	std::cout << "primary template\n";
}

template <>
void func(std::string &&) // explicit spec. for string &&
{
	std::cout << "full specialization\n";
}


int main()
{
	std::string name{ "necati" };
	func(name);
	func(std::string{ "ergin" });
}

