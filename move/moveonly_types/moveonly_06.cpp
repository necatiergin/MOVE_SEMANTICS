#include <vector>
#include <string>
#include <memory>
#include <iostream>

using usptr = std::unique_ptr<std::string>;

int main()
{
	std::vector<usptr> vec;

	usptr uptr{ new std::string{"Murat"} };

	vec.push_back(usptr{ new std::string{"Kaveh"} });
	vec.push_back(std::move(uptr));
	vec.push_back(std::make_unique<std::string>("Selim"));
	vec.emplace_back(new std::string{ "Mehmet" });
	vec.emplace_back();

	for (const auto& up : vec)
		std::cout << (up ? *up : "empty") << '\n';
}
