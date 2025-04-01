#include <iostream>
#include <type_traits>

class Nec {

};


int main()
{
	using namespace std;

	boolalpha(cout);
	cout << "is default constructor noexcept : " << is_nothrow_default_constructible_v<Nec> << '\n';
	cout << "is destructor noexcept          : " << is_nothrow_destructible_v<Nec> << '\n';
	cout << "is copy ctor noexcept           : " << is_nothrow_copy_constructible_v<Nec> << '\n';
	cout << "is move ctor noexcept           : " << is_nothrow_move_constructible_v<Nec> << '\n';
	cout << "is copy assignment noexcept     : " << is_nothrow_copy_assignable_v<Nec> << '\n';
	cout << "is move assignment noexcept     : " << is_nothrow_move_assignable_v<Nec> << '\n';
}
