#include <vector>
#include <list>
#include <string>
#include <memory>
#include <iostream>

using usptr = std::unique_ptr<std::string>;

int main()
{
	std::vector<usptr> vec;
	const char* pa[] = { "Yesim", "Deniz", "Murat", "Ahmet", "Hakan" };

	for (auto p : pa) {
		vec.push_back(std::make_unique<std::string>(p));
	}

	//std::list<usptr> ulist{ vec.begin(), vec.end() }; //gecersiz
	std::list<usptr> ulist{ std::make_move_iterator(vec.begin()),
							std::make_move_iterator(vec.end()) };

	for (const auto& up : vec)
		std::cout << (up ? *up : "empty") << ' ';

	std::cout << "\n";

	for (const auto& up : ulist)
		std::cout << (up ? *up : "empty") << ' ';
}
