#include <iostream>
#include <variant>
#include <string>

class Nec {
public:
    Nec(const std::string& str) : mval(str) 
    {
        std::cout << "Nec(const std::string&)\n";
    }
    Nec(const Nec& other) : mval(other.mval) 
    {
        std::cout << "Nec copy ctor\n";
    }
private:
    std::string mval;
};

std::variant<Nec, int> createObject(bool flag) 
{
    if (flag) {
        Nec obj("variant object");
        return obj; 
    }
    else {
        return 42; 
    }
}

int main() 
{
    auto obj = createObject(true);
}
