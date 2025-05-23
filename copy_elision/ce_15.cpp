// NO NRVO

#include <iostream>
#include <cstdlib>

struct Nec {
    Nec() { std::cout << "default constructor\n"; }
    Nec(const Nec&) { std::cout << "copy constructor\n"; }
    Nec(Nec&&) { std::cout << "move constructor\n"; }
    ~Nec() { std::cout << "destructor\n"; }
};

Nec foo(bool b) 
{
    Nec necx;
    Nec necy;

    return b ? necx : necy;
}

int main() 
{
    Nec s = foo(rand() % 2 == 0);
}
