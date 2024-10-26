#include <utility>

class Nec {
public:
	void foo()&;
	void bar()&&;
	void baz()const &;
	void bom()const &&;
};

int main()
{
	Nec nec;
	const Nec cnec;

	nec.foo();
	//nec.bar();	 // error
	nec.baz();
	//nec.bom();	 // error

	//cnec.foo();	 // error
	//cnec.bar();	 // error
	cnec.baz();
	//cnec.bom();	 // error

	//Nec{}.foo();	 //error
	Nec{}.bar();
	Nec{}.baz();
	Nec{}.bom();

	//std::move(cnec).foo();  //error
	//std::move(cnec).bar();  //error
	std::move(cnec).baz();
	std::move(cnec).bom();
}
