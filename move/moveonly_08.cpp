#include <vector>
#include <string>
#include <memory>

using usptr = std::unique_ptr<std::string>;

int main()
{
	usptr upx = std::make_unique<std::string>("necati");
	usptr upy = std::make_unique<std::string>("yunus");
	usptr upz = std::make_unique<std::string>("murat");
	usptr upt = std::make_unique<std::string>("tuana");

	std::vector<usptr> vec{
		std::move(upx),
		std::move(upy),
		std::move(upz),
		std::move(upt), };  //invalid
}
