//Bu örnek noexcept operatörü ile ilgilidir.
//noexcept operatörü noexcept belirteci (specifier) ile karıştırılmamalı

#include <iostream>

void f1();
void f2()noexcept;
auto fx = [] {};
auto fy = []()noexcept {};


class Nec {
public:
	~Nec() {};
};
int main()
{
	std::cout << std::boolalpha;
	std::cout << noexcept(f1()) << "\n";  //false
	std::cout << noexcept(f2()) << "\n";  //true
	std::cout << noexcept(fx()) << "\n";  //false
	std::cout << noexcept(fy()) << "\n";  // true
	std::cout << noexcept(std::declval<Nec>().~Nec()) << "\n";  //true
	constexpr auto flag = noexcept(fx()); //gecerli
}
