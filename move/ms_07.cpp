#include <string>

void foo(const std::string& s)
{
	std::string str = s;  //str is copy constructed
	//...
}

void foo(std::string&& s)
{
	std::string str = std::move(s);  //str is move constructed
	//...
}

void bar(const std::string& s)
{
	std::string str;
	//...
	str = s;  //str is copy assigned
	//...
}

void bar(std::string&& s)
{
	std::string str;
	//...

	str = std::move(s);  //str is move assigned
	//...
}
