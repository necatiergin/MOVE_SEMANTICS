class Nec {
public:
	void foo()&;
	void foo() const; // invalid
	//reference qualified member function cannot overload reference unqualified one.
};
