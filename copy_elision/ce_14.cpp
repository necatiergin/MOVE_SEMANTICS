// no NRVO 

#include <iostream>

struct Nec {
    Nec() { std::cout << "default constructor\n"; }
    Nec(const Nec&) { std::cout << "copy constructor\n"; }
    Nec(Nec&&) { std::cout << "move constructor\n"; }
    ~Nec() { std::cout << "destructor\n"; }
};

Nec foo() 
{
    static Nec nec; 

    return nec;
}

int main() 
{
    Nec s = foo();
}
