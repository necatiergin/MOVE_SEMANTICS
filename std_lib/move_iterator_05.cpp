#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
void print_container(const std::string& name, const T& con)
{
    std::cout << name << " (" << con.size() << " elements): ";
    for (const auto& elem : con) {
        std::cout << "[" << elem << "] ";
    }
    std::cout << '\n';
}

void foo(std::string s)  
{
    std::cout << "- foo(" << s << ")\n";
    //...
}

int main()
{
    std::vector<std::string> svec{ "ali", "mert", "ayse", "kamil", "necati", "orhan", "turgut", "gul" };
    print_container("svec", svec);

    std::for_each(std::make_move_iterator(svec.begin()),
        std::make_move_iterator(svec.end()),
        [](std::string&& elem) {
            if (elem.length() != 5) {
                foo(std::move(elem));
            }
        });

    print_container("svec", svec);
}
