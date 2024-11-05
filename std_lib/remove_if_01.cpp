#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class StrWrapper {
public:
	StrWrapper() = default;
	~StrWrapper() = default;
	StrWrapper(const std::string& s) : m_str(s) {}
	StrWrapper(const StrWrapper&) = default;
	StrWrapper& operator=(const StrWrapper&) = default;
	StrWrapper(StrWrapper&& other) noexcept : m_str(std::move(other.m_str)) 
	{
		std::cout << "move ctor.\n";
	}

	StrWrapper& operator=(StrWrapper&& other) noexcept
	{
		std::cout << "move assignment.\n";
		
		if (&other != this)
			m_str = std::move(other.m_str);
		
		return *this;
	}

	std::size_t length()const { return m_str.length(); }
private:

	std::string m_str{};
};

int main()
{
	using namespace std::literals;

	std::vector<StrWrapper> svec;
	svec.reserve(20);
	svec.emplace_back("kemal");
	svec.emplace_back("hasan");
	svec.emplace_back("can");
	svec.emplace_back("mert");
	svec.emplace_back("murat");

	//auto iter = std::remove_if(svec.begin(), svec.end(), [](const StrWrapper& s) { 	return s.length() == 5;});

}
