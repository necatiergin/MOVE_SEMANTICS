#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> get_name_vec()
{
	return { "alican", "velican" };
}

int main()
{
	auto&& range = get_name_vec().at(0); 
	//std::string &range  = get_name_vec().at(0); 
	auto iter = range.begin(); 
	auto end = range.end();
	for (; iter != end; ++iter) {
		char c = *iter;
		std::cout << c;
	}
}
