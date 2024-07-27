#include <vector>

template <typename C, typename T>
void set_elems(C& c, const T& val)
{
	for (auto& elem : c)
		elem = val;
}



int main()
{
	std::vector<bool> bvec{ true, false, true, false };

	set_elems(bvec, true); //error
}
