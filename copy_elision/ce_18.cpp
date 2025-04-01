#include <iostream>

struct Nec {
    Nec() { std::cout << "Constructor\n"; }
    Nec(const Nec&) { std::cout << "Copy constructor\n"; }
    Nec(Nec&&) { std::cout << "Move constructor\n"; }
    ~Nec() { std::cout << "Destructor\n"; }
};

Nec foo(Nec nec) 
{
    return nec; 
}

int main() 
{
    Nec x;

    Nec nec = foo(x);
}
