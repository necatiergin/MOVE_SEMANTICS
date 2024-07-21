#include <iostream>

class Myclass {
public:
	Myclass()
	{
		std::cout << "default ctor    this : " << this << '\n';
	}

	~Myclass()
	{
		std::cout << "destructor      this : " << this << '\n';
	}

	Myclass(int)
	{
		std::cout << "Myclass(int) this : " << this << '\n';
	}

	Myclass(const Myclass&)
	{
		std::cout << "copy ctor       this : " << this << '\n';
	}

	Myclass(Myclass&&)
	{
		std::cout << "move ctor       this : " << this << '\n';
	}

	Myclass& operator=(const Myclass&)
	{
		std::cout << "copy assignment this : " << this << '\n';
		return *this;
	}

	Myclass& operator=(Myclass&&)
	{
		std::cout << "move assignment this : " << this << '\n';
		return *this;
	}
};



int main()
{
	Myclass m1{ 47 }; //Myclass(int);
	auto m2{ m1 }; //cc
	auto m3{ std::move(m1) }; //mc
	auto m4{ static_cast<Myclass&&>(m3) }; //mc
	m3 = m4; //copy assignment
	m3 = std::move(m4); //move assignment
}
