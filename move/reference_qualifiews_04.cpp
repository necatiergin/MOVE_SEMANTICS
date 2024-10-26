class Nec {
public:
	Nec(const Nec&) = default;
	Nec(Nec&&) = default;
	
	Nec& operator=(const Nec& str) & = default;
	Nec& operator=(Nec&& str) & = default;
};

Nec foo();

int main()
{
	foo() = foo(); //error
}
