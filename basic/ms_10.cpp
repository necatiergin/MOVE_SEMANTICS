#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    using namespace std;

    std::string name{ "necati ergin" };
    vector<string> svec;
    svec.reserve(10);
    svec.push_back(name); //strig copy ctor
    std::cout << "name is " << quoted(name) << '\n';

    svec.push_back(move(name));
    cout << "now name is " << quoted(name) << '\n'; //moved from state

    cout << "svec[0] is : " << quoted(svec[0]) << '\n';
    cout << "svec[1] is : " << quoted(svec[1]) << '\n';
}
