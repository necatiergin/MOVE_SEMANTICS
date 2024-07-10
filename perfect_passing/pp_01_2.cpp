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

	auto&& r1 = return_const_l_ref(cnec);
	foo(std::forward<decltype(r1)>(r1));   // calls foo(const Nec&)

	auto&& r2 = return_l_ref(nec);
	foo(std::forward<decltype(r2)>(r2));   // calls foo(Nec&)
	
	auto&& r3 = return_r_ref(Nec{});
	foo(std::forward<decltype(r3)>(r3));   // calls foo(Nec&&)
	
	auto&& r4 = return_value(nec);
	foo(std::forward<decltype(r4)>(r4));	// calls foo(Nec&&)
}
