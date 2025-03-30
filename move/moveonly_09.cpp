#include <vector>
#include <string>
#include <memory>

using usptr = std::unique_ptr<std::string>;

int main()
{
	usptr uptr = std::make_unique<std::string>("necati");

	std::vector<usptr> vec(5, uptr); //invalid
}
