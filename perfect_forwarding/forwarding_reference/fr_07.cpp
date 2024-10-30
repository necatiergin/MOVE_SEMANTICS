#include <vector>

template <typename T>
void foo(std::vector<T>&&); //not universal reference - R value reference

int main()
{
	std::vector<int> x(10);

	foo(x); //error
}
