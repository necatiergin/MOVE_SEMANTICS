#include <stack>
#include <iostream>

void foo(std::stack<int>)
{
	//...
}


int main()
{
	std::stack<int> st;

	for (int i = 0; i < 10; ++i) {
		st.push(i);
	}

	foo(move(st));
	st.push(42);

	std::cout << st.top(); //42
}
