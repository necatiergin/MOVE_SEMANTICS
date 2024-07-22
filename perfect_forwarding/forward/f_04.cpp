#include <string>
#include <iostream>


class Person
{
private:
	std::string name;
public:
	void print() const 
	{
		std::cout << "print()\n";
	}

	std::string getName()&& 
	{ 
		return std::move(name); 
	}

	const std::string& getName() const& 
	{
		return name; 
	}
};

template<typename T>
void foo(T&& x)
{
	x.print(); 
	auto s1 = x.getName(); 
	auto s2 = std::forward<T>(x).getName(); 
}
