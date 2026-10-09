template<typename T>
void foo(T&&);

int main()
{
	int x{};
	foo<int&>(x);    // parameter type: int&
	foo<int&&>(10);  // parameter type: int&&
	//...
}

