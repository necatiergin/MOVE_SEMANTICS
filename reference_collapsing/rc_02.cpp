class Myclass {};

template <typename T>
void func(T&param){}

template <typename T>
void foo(T&& param) {}

int main()
{
	Myclass m;
	func<Myclass&>(m); //param is Myclass &
	func<Myclass&&>(m); //param is Myclass &
	foo<Myclass&>(m); //param is Myclass &
	foo<Myclass&&>(Myclass{}); //param is Myclass &&
}
