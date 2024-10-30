// a simple std::forward implementation

template<class T>
constexpr T&& forward(typename std::remove_reference<T>::type& t) noexcept 
{
	return static_cast<T&&>(t);
}
