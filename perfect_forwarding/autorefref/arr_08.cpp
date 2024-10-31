#include <vector>

template <typename C, typename T>
void fill(C& con, const T& val)
{
	//for (auto&& elem : con)
	for (auto& elem : con)
		elem = val;
}

int main()
{
	std::vector<int> ivec(20);
	fill(ivec, 10); //valid
	
	std::vector<bool> bvec(20);
	fill(bvec, true); //error
}
