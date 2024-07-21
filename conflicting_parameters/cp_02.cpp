#include <vector>
#include <string>

template<typename T>
void insert(std::vector<std::remove_reference_t<T>>& vec, T&& elem)
{
	vec.push_back(std::forward<T>(elem));
}

int main()
{
	std::vector<std::string> vec;
	std::string s;

	insert(vec, s);
}
