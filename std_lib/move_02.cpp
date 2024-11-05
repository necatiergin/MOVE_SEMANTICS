#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iostream>

template <typename T>
void print_container(const std::string& name, const T& con)
{
	std::cout << name << " (" << con.size() << " elements): ";
	for (const auto& elem : con) {
		std::cout << " '" << elem << "'";
	}
	std::cout << '\n';
}


int main()
{
	std::deque<std::string> sdeq{ "C++", "is", "the", "best", "programming", "language"};
	std::vector<std::string> svec;
	svec.resize(sdeq.size());
	print_container("sdeq", sdeq);
	print_container("svec", svec);
	std::move(sdeq.begin(), sdeq.end(), svec.begin()); 
	print_container("sdeq", sdeq);
	print_container("svec", svec);
	std::move_backward(svec.begin(), next(svec.begin(), 4), svec.end()); 
	print_container("sdeq", sdeq);
	print_container("svec", svec);
}
