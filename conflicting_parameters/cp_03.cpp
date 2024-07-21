#include <vector>
#include <string>

template<typename ElemType, typename T>
void insert(std::vector<ElemType>& vec, T&& elem)
{
	vec.push_back(std::forward<T>(elem));
}

int main()
{
	std::vector<std::string> vec;
	std::string s;

	insert(vec, s);
}
