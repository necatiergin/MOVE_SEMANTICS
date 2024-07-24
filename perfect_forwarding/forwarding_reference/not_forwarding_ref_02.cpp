#include <string>

template <typename T>
struct Nec {
	//...
	void foo(T&&) {} // not universal reference - R value reference

	template <typename U>
	void bar(U &&) {} // universal reference
};

int main()
{
	Nec<std::string> x;
	std::string str{ "necati" };

	//x.foo(str); //error
	x.bar(str); // valid
	x.bar(std::string{"ergin"}); // valid
}
