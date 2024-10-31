//check compiler error messages for each call

#include <utility>

template <typename T>
class TypeTeller;


template <typename T>
void func(T&&)
{
	TypeTeller<T> x;
}


class Myclass {};

int main()
{
	Myclass m;
	const Myclass cm;

	//func(m);
	//func(cm);
	//func(Myclass{});
	//func(std::move(m));
	//func(std::move(cm));
}
