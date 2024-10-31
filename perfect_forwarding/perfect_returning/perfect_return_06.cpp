int main()
{
	auto f = [](auto func, auto&&... args) -> decltype(auto) {
		return func(std::forward<decltype(args)>(args)...);
	};
}
