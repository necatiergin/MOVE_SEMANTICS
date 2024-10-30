template <typename T>
void func(T&&, T&, T);

int main()
{
	int x = 10;

	func(1, x, x);
	func(x, x, x); //error
}
