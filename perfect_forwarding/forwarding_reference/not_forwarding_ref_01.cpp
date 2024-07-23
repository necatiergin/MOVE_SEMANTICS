#include <string>

template <typename T>
void func(const T&&); //not forwarding reference const R value reference

int main()
{
	std::string str{ "necati" };

	func(str); //error 
}
