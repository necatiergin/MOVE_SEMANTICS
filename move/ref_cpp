#include <vector>
#include <algorithm>
#include <functional>


struct BigPred {
	bool operator()(int);
	unsigned char buffer[10000]{};
};

int main()
{
	std::vector<int> ivec(2000);
	///...
	BigPred pred;

	//aradaki fark ne
	auto nx = count_if(begin(ivec), end(ivec), pred);
	auto ny = count_if(begin(ivec), end(ivec), std::ref(pred));

}
