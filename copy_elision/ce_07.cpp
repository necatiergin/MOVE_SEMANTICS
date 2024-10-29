#include <iostream>

class Nec {
public:
	Nec()
	{
		std::cout << "default ctor called\n";
	}

	Nec(const Nec&) = delete;
};


Nec func()
{
	Nec nec;
	//use nec
	return nec; //error
}

int main()
{
	Nec m{ func() };
}
