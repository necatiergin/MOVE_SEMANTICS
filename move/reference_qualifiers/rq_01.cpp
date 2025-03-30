#include <iostream>

class Nec {
public:
	void func()& 
	{
		std::cout << "Nec::func()&\n";
	}

	void func()&& 
	{
		std::cout << "Nec::func()&&\n";
	}

	void func()const& 
	{
		std::cout << "Nec::func()const &\n";
	}

	void func()const&& 
	{
		std::cout << "Nec::func()const &&\n";
	}
};


int main()
{
	Nec ax;
	const Nec ca;

	ax.func(); // Nec::func()&
	ca.func(); // Nec::func() const &
	Nec{}.func(); // Nec::func()&&
	std::move(ax).func(); // Nec::func()&&
	std::move(ca).func(); // Nec::func()const &&
}
