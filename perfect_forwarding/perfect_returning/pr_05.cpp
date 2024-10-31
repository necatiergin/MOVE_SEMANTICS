#include <utility>

//call_foo fonksiyonu'nun geri dönüş değeri türü foo'nun geri dönüş türü olacak
// value category ve const'luk korunacak

template<typename T>
decltype(auto) call_foo(T && arg)
{
	return foo(std::forward<T>(arg));
}
