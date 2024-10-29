#include <iostream>

class Nec {
public:
	Nec() = default;

	Nec(int x) : mx{ x }
	{
		std::cout << "Nec(int)\n";
	}

	void fold(int x)
	{
		mx *= x;
	}

	void print()const
	{
		std::cout << mx << '\n';
	}

private:
	int mx{};
};


Nec make_nec(int val)
{
	return Nec{ val };
}

Nec func()
{
	Nec x = make_nec(20);
	x.fold(10);
	return x;
}

int main()
{
	Nec mynec = func();

	mynec.print();
}
