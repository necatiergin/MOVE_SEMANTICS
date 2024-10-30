#include <vector>
#include <string>

template<typename Container, typename T>
void insert(Container &con, T&& elem)
{
	con.push_back(std::forward<T>(elem));
}

int main()
{
	std::vector<std::string> vec;
	std::string s;

	insert(vec, s);
}
