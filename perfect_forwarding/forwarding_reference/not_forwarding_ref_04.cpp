#include <iostream>
#include <string>
#include <vector>

template<typename C>
void push_back(C& con, typename C::value_type&& arg)  // not forwarding reference, R value reference
{
	con.push_back(arg);
}

int main()
{
	std::vector<std::string> svec;
	//...
	push_back(svec, std::string{ "necati" });  // OK
	//...
	std::string name{ "ergin" };
	//push_back(svec, name);              // error
	push_back(svec, std::move(name));   // OK
	//...
}
