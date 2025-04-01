#include <iostream>

struct Nec {
    Nec() { std::cout << "default constructor\n"; }
    Nec(const Nec&) { std::cout << "copy constructor\n"; }
    Nec(Nec&&) { std::cout << "move constructor\n"; }
    ~Nec() { std::cout << "destructor\n"; }
};

Nec foo();

int main() 
{
    Nec nec = foo();
}

Nec foo()
{
    Nec necx;
    Nec necy = necx;

    return necy;
}
