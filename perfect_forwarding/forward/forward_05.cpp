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

	std::string getName()const&&
	{
		std::cout << "const&&\n";
		return std::move(name);
	}

	const std::string& getName() const&
	{
		std::cout << "const&\n";
		return name;
	}
};

template<typename T>
void foo(T&& x)
{
	x.print();
	auto s = std::forward<T>(x).getName();
}

int main()
{
	Person p;
	foo(p);
}


