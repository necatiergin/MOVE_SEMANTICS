#include <iostream>
#include <vector>

class MoveOnly {
public:
	MoveOnly();
	MoveOnly(MoveOnly&&);
	MoveOnly& operator=(MoveOnly&&);
	//...	
};

int main()
{
	std::vector<MoveOnly> svec(10);

	//for (auto m : svec) {}  //error
	for (auto &m : svec) {}  //valid
	for (const auto &m : svec) {}  //valid
	for (auto &&m : svec) {}  //valid
}
