#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::ifstream open_text_file(const std::string& filename)
{
	std::ifstream ifs{filename};
	if (!ifs)
		throw std::runtime_error{ filename + "cannot be opened!" };
	
	return ifs;
}

int main()
{
	auto ifs = open_text_file("xyz.txt");

	std::string sline;
	std::vector<std::string> svec;

	//the object in moved from state is reassigned

	while (getline(ifs, sline))
		svec.push_back(move(sline));

}
