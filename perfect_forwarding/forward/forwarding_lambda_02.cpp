int main()
{
	auto f = [](auto&&... args) {
		foo(std::forward<decltype(args)>(args)...);
	};
}
