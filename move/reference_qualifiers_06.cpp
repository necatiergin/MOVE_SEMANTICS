#include <iostream>

class Nec {
public:
	void foo()& { std::cout << "foo()&\n";}
	void foo()const & { std::cout << "foo()const &\n";}
	void foo()&& { std::cout << "foo()&&\n";}
	void foo()const && { std::cout << "foo()const &&\n";}
};

int main()
{
	Nec nec;
	const Nec cnec;

	nec.foo();
	cnec.foo();
	Nec{}.foo();
	std::move(cnec).foo();
}
