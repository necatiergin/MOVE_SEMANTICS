// No NRVO - pessimistic move

#include <iostream>

struct Nec {
    Nec() { std::cout << "default constructor\n"; }
    Nec(const Nec&) { std::cout << "copy constructor\n"; }
    Nec(Nec&&) { std::cout << "move constructor\n"; }
    ~Nec() { std::cout << "destructor\n"; }
};

Nec foo() 
{
    Nec necx;

    return std::move(necx);
}

int main() 
{
    Nec s = foo();
}
