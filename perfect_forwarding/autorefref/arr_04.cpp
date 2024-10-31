#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec{ 2, 3, 5, 7, 11, 13, 17 };

	for (auto i : ivec)
		std::cout << i << ' ';
	std::cout << '\n';

	auto&& range = ivec;
	for (auto ibeg = begin(range), iend = end(range); ibeg != iend; ++ibeg) {
		auto i = *ibeg;
		std::cout << i << ' ';
	}
}
