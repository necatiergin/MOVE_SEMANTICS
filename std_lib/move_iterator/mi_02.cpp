#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <iomanip>

int main()
{
	std::vector<std::string> svec{ "the ", "good ", "the ", "bad ", "and ", "the ", "ugly " };
	//std::move_iterator<std::vector<std::string>::iterator> 	iter(svec.begin());
	//std::move_iterator iter(svec.begin()); //since C++ 17
	auto iter = std::make_move_iterator(svec.begin());
	auto end = std::make_move_iterator(svec.end());

	std::vector<std::string> destvec;

	while (iter != end) 
		destvec.push_back(*iter++);

	for (const auto& s : svec) {
		std::cout << std::quoted(s) << '\n';
	}
}

