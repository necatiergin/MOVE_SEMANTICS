// sample std::move implementation

#include <iostream>
#include <type_traits>

template <typename T>
constexpr std::remove_reference_t<T>&& 
Move(T&& x)noexcept
{
	return static_cast<std::remove_reference_t<T>&&>(x);
}
