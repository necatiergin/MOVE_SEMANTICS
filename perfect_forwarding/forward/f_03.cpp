#include <iostream>

class Nec {};

void f(Nec &)
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

template <typename T>
void call_f(T&& t)
{
	f(std::forward<decltype(t)&&>(t));
}

int main()
{
	Nec n;
	const Nec cn;
	auto call_f = [](auto&& x) {f(std::forward<decltype(x)>(x)); };

	f(n);
	call_f(n);
	std::cout << "------------------\n";
	f(cn);
	call_f(cn);
	std::cout << "------------------\n";
	f(Nec{});
	call_f(Nec{});
	std::cout << "------------------\n";
	f(std::move(n));
	call_f(std::move(n));
	std::cout << "------------------\n";
	f(std::move(cn));
	call_f(std::move(cn));
	std::cout << "------------------\n";
}
