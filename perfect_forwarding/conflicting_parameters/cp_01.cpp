#include <vector>
#include <string>

template <typename T>
void insert(std::vector<T>& vec, T&& elem)
{
	vec.push_back(std::forward<T>(elem));
}

int main()
{
	std::vector<std::string> coll;
	std::string s;

	insert(vec, s); //gecersiz
}
