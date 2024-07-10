#include <iostream>

//perfect passing

class Nec{};

void foo(const Nec&) 
{
	std::cout << "foo(const Nec&)\n";
}

void foo(Nec&) 
{
	std::cout << "foo(Nec&)\n";
}

void foo(Nec&&) 
{
	std::cout << "foo(Nec &&)\n";
}

const Nec& return_const_l_ref(const Nec& nec) 
{
	return nec;
}

Nec& return_l_ref(Nec& nec) 
{
	return nec;
}

Nec&& return_r_ref(Nec&& nec) 
{
	return std::move(nec);
}

Nec return_value(const Nec& nec) 
{
	return nec;
}

int main()
{
	Nec nec;
	const Nec cnec;

	foo(return_const_l_ref(cnec));   // calls foo(const Nec&)
	foo(return_l_ref(nec));          // calls foo(Nec&)
	foo(return_r_ref(Nec{}));        // calls foo(Nec&&)
	foo(return_value(nec));          // calls foo(Nec&&)
}
