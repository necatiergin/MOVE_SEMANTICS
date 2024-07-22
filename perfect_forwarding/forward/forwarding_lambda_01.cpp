#include <iostream>

class Nec {};

void f(Nec&)
{
	std::cout << "f(Nec &)\n";
}

void f(const Nec&)
{
	std::cout << "f(const Nec &)\n";
}

void f(Nec&&)
{
	std::cout << "f(Nec &&)\n";
}

void f(const Nec&&)
{
	std::cout << "f(const Nec &&)\n";
}

int main()
{
	auto call_f = [](auto&& ur) {
		f(std::forward<decltype(ur)>(ur));
	};

	Nec nec;
	const Nec c_nec;

	f(nec); call_f(nec);
	std::cout << "--------------------\n";
	f(c_nec); call_f(c_nec);
	std::cout << "--------------------\n";
	f(Nec{}); call_f(Nec{});
	std::cout << "--------------------\n";
	f(std::move(nec)); call_f(std::move(nec));
	std::cout << "--------------------\n";
	f(std::move(c_nec)); call_f(std::move(c_nec));

}
