#include <iostream>
#include <array>


class Nec {
public:
	Nec() = default;
	Nec(const Nec&)
	{
		std::cout << "copy ctor\n";
	}

	Nec(Nec&&)
	{
		std::cout << "move ctor\n";
	}
};

int main()
{
	std::array<Nec, 5> ax;
	//auto ay = ax; //copy ctor O(n)
	auto ay = std::move(ax); //move ctor O(n)
}
