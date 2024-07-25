#include <iostream>
#include <string>
#include <vector>
#include <chrono>

struct StrWrapper
{
	// ensure each string has 1000 characters:
	StrWrapper() : m_str(100, 'x') { }

	StrWrapper(const StrWrapper&) = default;

	StrWrapper(StrWrapper&& other)noexcept : m_str{ std::move(other.m_str) } {}
private:
	std::string m_str;
};

int main()
{
	std::vector<StrWrapper> svec;
	svec.resize(1'000'000u);

	auto t_start = std::chrono::steady_clock::now();
	svec.reserve(svec.capacity() + 1);
	auto t_end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double, std::milli>{ t_end - t_start } << '\n';
}
