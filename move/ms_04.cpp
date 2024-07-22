#include <iostream>


class MoveOnly {
public:
	MoveOnly(int)
	{
		std::cout << "MoveOnly(int)\n";
	}
	MoveOnly(const MoveOnly&) = delete;
	MoveOnly& operator=(const MoveOnly&) = delete;
	MoveOnly(MoveOnly&&)
	{
		std::cout << "move ctor\n";
	}

	MoveOnly& operator=(MoveOnly&&)
	{
		std::cout << "move assignment\n";
		return *this;
	}
};



MoveOnly foo(int ival)
{
	MoveOnly m{ ival};

	return m; //copy elisison or move ctor
}

int main()
{
	auto m = foo(12);
}
