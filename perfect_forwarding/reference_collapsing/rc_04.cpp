#include <string>

int main(void)
{
	using lref = std::string &;
	using rref = std::string &&;

	std::string name{ "necati" };

	lref& r1{ name }; // r1  ==> std::string &
	lref&& r2{ name}; // r2  ==> std::string &
	rref& r3{ name }; // r3  ==> std::string &
	rref&& r4{ std::move(name)}; // r4  ==> std::string &&
}
