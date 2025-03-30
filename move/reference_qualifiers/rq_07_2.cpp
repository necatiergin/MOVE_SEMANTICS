#include <iostream>
#include <string>

class Sentence {
public:
	Sentence(const char *ps) : mstr(ps) {}
	std::string str()&&
	{
		return std::move(mstr);
	}

	const std::string& str()&
	{
		return mstr;
	}
private:
	std::string mstr;
};

Sentence get_sentence()
{
	Sentence s{ "be aware of temporary objects and life extension rules" };

	return s;
}


int main()
{
	for (auto c : get_sentence().str()) {
		std::cout.put(c);
	}
}
