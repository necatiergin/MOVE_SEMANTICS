#include <vector>
#include <list>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>

using usptr = std::unique_ptr<std::string>;

int main()
{
	std::vector<usptr> vec;
	const char* pa[] = { "Yesim", "Deniz", "Murat", "Ahmet", "Hakan" };

	for (auto p : pa) {
		vec.push_back(std::make_unique<std::string>(p));
	}

	std::list<usptr> ulist(vec.size());

	//std::copy(vec.begin(), vec.end(), ulist.begin());
	std::move(vec.begin(), vec.end(), ulist.begin());

	for (const auto& up : vec)
		std::cout << (up ? *up : "empty") << ' ';

	std::cout << "\n";

	for (const auto& up : ulist)
		std::cout << (up ? *up : "empty") << ' ';
}
