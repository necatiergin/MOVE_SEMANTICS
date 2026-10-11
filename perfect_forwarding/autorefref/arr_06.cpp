#include <iostream>

//perfect passing
//deferred perfect passing

class Nec {};

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

const Nec& bar1(const Nec& nec)
{
	return nec;
}

Nec& bar2(Nec& nec)
{
	return nec;
}

Nec&& bar3(Nec&& nec)
{
	return std::move(nec);
}

Nec bar4(const Nec& nec)
{
	return nec;
}

int main()
{
	Nec nec;
	const Nec cnec;

	foo(bar1(cnec));
	auto&& r1 = bar1(cnec);
	foo(std::forward<decltype(r1)>(r1));   // calls foo(const Nec&)

	foo(bar2(nec));
	auto&& r2 = bar2(nec);
	foo(std::forward<decltype(r2)>(r2));   // calls foo(Nec&)

	foo(bar3(Nec{}));
	auto&& r3 = bar3(Nec{});
	foo(std::forward<decltype(r3)>(r3));   // calls foo(Nec&&)

	foo(bar4(nec));
	auto&& r4 = bar4(nec);
	foo(std::forward<decltype(r4)>(r4));	// calls foo(Nec&&)
}
