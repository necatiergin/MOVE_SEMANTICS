#include <vector>
#include <iostream>

class MoveOnly {
public:
	MoveOnly() = default;
	MoveOnly(const MoveOnly&) = delete;
	MoveOnly& operator=(const MoveOnly&) = delete;

	MoveOnly(MoveOnly&&) = default;
	MoveOnly& operator=(MoveOnly&&) = default;
	//....
};


int main()
{
	std::vector<MoveOnly> vec;
	vec.reserve(10);

	MoveOnly mx;

	vec.push_back(MoveOnly());
	vec.push_back(std::move(mx));
	vec.emplace_back();
	
	std::cout << "size = " << vec.size() << '\n';
	//auto m1 = vec[1]; //error
	auto m2 = std::move(vec[1]); //valid
	std::cout << "size = " << vec.size() << '\n';

}
