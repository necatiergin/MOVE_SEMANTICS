#include <string>
#include <algorithm>

//iki fonksiyonu karsilastirin

void func(const std::string &s)
{
	auto s_copy{ s };
	reverse(begin(s_copy), end(s_copy));
	//...
}

void func(std::string s)
{
	reverse(begin(s), end(s));
	//...
}
