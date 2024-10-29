#include <memory>
#include <string>

std::unique_ptr<std::string> foo(const char* p)
{
	return std::make_unique<std::string>(p);  //mandatory copy elision
}


std::unique_ptr<std::string> bar(const char* p)
{
	auto uptr = std::make_unique<std::string>(p);

	return uptr; 
}

int main()
{
	auto upx{ foo("necati ergin") };
	auto upy{ foo("ali kalan") };
}
