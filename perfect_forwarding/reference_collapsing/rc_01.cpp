#include <utility>


template <typename T>
void foo(T&& r)
{

}

int main()
{
	int x{};
	const int cx{};

	foo(x); //T is int& r is int & 
	foo(cx); //T is const int& r is const int &
	foo(5); // T is int r is int &&
	foo(std::move(x)); // T is int, r is int &&
	foo(std::move(cx)); // T is const int, r is const int &&
}
