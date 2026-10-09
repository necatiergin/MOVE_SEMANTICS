#include <utility>

int x{};
int& r{ x };
int&& rr = 10;

int main()
{
	decltype(r)& r1{ x }; // int& r1{x};
	decltype(r)&& r2{ x }; // int& r2{x};
	decltype(rr)& r3{ x }; // int& r3{x};
	decltype(rr)&& r4{ 20 }; // int&& r4{20};
}
