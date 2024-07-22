#include <iostream>

class Nec {};

void f(Nec&)
{
	std::cout << "Nec&\n";
}

void f(const Nec&)
{
	std::cout << "const Nec&\n";
}

void f(Nec&&)
{
	std::cout << "Nec&&\n";
}

void f(const Nec&&)
{
	std::cout << "const Nec&&\n";
}

Nec& foo_ret_lref(Nec& r)
{
	return r;
}

const Nec& foo_ret_const_lref(const Nec& r)
{
	return r;
}

Nec&& foo_ret_rref(Nec&& r)
{
	return std::move(r);
}

const Nec&& foo_ret_const_rref(const Nec&& r)
{
	return std::move(r);
}

Nec foo_ret_value()
{
	Nec nec;

	return nec;
}

int main()
{
	Nec nx;
	Nec cnec;

	/*f(foo_ret_lref(nx));
	f(foo_ret_const_lref(nx));
	f(foo_ret_rref(Nec{}));
	f(foo_ret_const_rref(std::move(cnec)));
	f(foo_ret_value());*/

	auto &&r1 = foo_ret_lref(nx);
	f(std::forward<decltype(r1)>(r1));
	auto&& r2 = foo_ret_const_lref(nx);
	f(std::forward<decltype(r2)>(r2));
	auto&& r3 = foo_ret_rref(Nec{});
	f(std::forward<decltype(r3)>(r3));
	auto&& r4 = foo_ret_const_rref(std::move(cnec));
	f(std::forward<decltype(r4)>(r4));
	auto&& r5 = foo_ret_value();
	f(std::forward<decltype(r5)>(r5));
}
