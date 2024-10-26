class Nec {};
class Erg {
	//
	Erg& operator=(const Erg&)&;
};

Nec foo();
Erg bar();


int main()
{
	Nec() = Nec();	 //valid
	foo() = foo();	 //valid
	//Erg() = Erg();	 //error
	//bar() = bar();	 //error
}
