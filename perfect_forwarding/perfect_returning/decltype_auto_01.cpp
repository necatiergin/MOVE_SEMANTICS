#include <utility>

class Myclass{};
Myclass foo();
Myclass& bar();
Myclass&& baz();

int main()
{
	Myclass mx;
	const Myclass cmx;
	Myclass& r = mx;
	const Myclass& cr = mx;

	decltype(auto) m1 = mx;					//Myclass m1 = mx;
	decltype(auto) m2 = cmx;				//const Myclass m2 = cmx;
	decltype(auto) m3 = r;					//Myclass& m3 = r;
	decltype(auto) m4 = cr;					//const Myclass& m4 = cr;
	decltype(auto) m5 = foo();				//Myclass m5 = foo();
	decltype(auto) m6 = bar();				//Myclass& m6 = bar();
	decltype(auto) m7 = baz();				//Myclass&& m7 = baz();
	decltype(auto) m8 = (mx);				//Myclass& m8 = mx;
	decltype(auto) m9 = (cmx);				//const Myclass& m9 = cmx;
	decltype(auto) m10 = (r);				//Myclass& m10 = r;
	decltype(auto) m11 = (cr);				//const Myclass& m11 = cr;
	decltype(auto) m12 = std::move(mx);		//Myclass&& m12 = std::move(mx);
	decltype(auto) m13 = std::move(cmx);	//const Myclass&& m13 = std::move(cmx);
	decltype(auto) m14 = Myclass{};			//Myclass m14 = Myclass{}
}
