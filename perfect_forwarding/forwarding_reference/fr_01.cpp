//reference collapsing rules

class Myclass {};

using LRef = Myclass&;
using RRef = Myclass&&;

int main()
{
	Myclass m;
	LRef& r1 = m;  //r1 is Myclass &
	LRef&& r2 = m;  //r2 is Myclass &
	RRef& r3 = m; // r3 is Myclass &
	RRef&& r4 = Myclass{}; // r4 is Myclass &&
}
