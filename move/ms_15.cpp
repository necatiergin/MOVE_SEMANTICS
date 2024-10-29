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

	//asagidaki dongude moved-from durumundaki nesne tekrar kullaniliyor

	while (getline(ifs, sline))
		svec.push_back(move(sline));

}
