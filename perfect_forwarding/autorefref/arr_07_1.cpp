#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> get_name_vec()
{
	return { "alican", "velican" };
}

int main()
{
	for (auto c : get_name_vec().at(0)) { //ub
		std::cout.put(c);
	}
}
