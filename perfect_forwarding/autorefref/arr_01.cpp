#include <vector>
#include <iostream>
#include <string>

template<typename Con, typename T>
void Fill(Con& c, const T& value) {
	for (auto& elem : c) {
	//for (auto&& elem : c) {
		elem = value;
	}
}

int main()
{
	using namespace std;

	vector<int> ivec(20);
	vector<string> svec(20);
	vector<bool> bvec(20);

	Fill(ivec, 1);
	Fill(svec, "necati");
	Fill(bvec, true);
}


