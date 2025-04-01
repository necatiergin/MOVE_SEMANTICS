#include <string>
#include <iostream>

int main()
{

	std::string sx(100'000, 'A');

	std::cout << "sx.size() = " << sx.size() << "\n";
	std::cout << "sx.capacity() = " << sx.capacity() << "\n";

	std::string sy(150, 'Z');

	std::cout << "sy.size() = " << sy.size() << "\n";
	std::cout << "sy.capacity() = " << sy.capacity() << "\n";


	sx = std::move(sy);

	std::cout << "sx.size() = " << sx.size() << "\n";
	std::cout << "sx.capacity() = " << sx.capacity() << "\n";
}
