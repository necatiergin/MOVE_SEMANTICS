#include <string>
#include <iostream>

void foo(std::string&) { std::cout << "foo(string &)\n"; }  //1
void foo(const std::string&) { std::cout << "foo(const string &)\n"; }  //2
void foo(std::string&&) { std::cout << "foo(string &&)\n"; } //3
void foo(const std::string&&) { std::cout << "foo(const string &&)\n"; } //4

int main()
{
	std::string s{ "l Value" };
	const std::string cs{ "const l Value" };

	//foo(s); // 1 2 (3 4 error)
	//foo(cs); // 2 (1 3 4 error)
	//foo(std::move(s)); //3 4 2 (1 error)
	//foo(std::move(cs)); // 4 2 (1 3 error)

}
