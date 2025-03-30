#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>


struct StrWrapper
{
	// ensure each string has 1000 characters:
	StrWrapper() : m_str(1000, 'x') {}

	StrWrapper(const StrWrapper&) = default;

	StrWrapper(StrWrapper&& other) : m_str{ std::move(other.m_str) } {}
private:
	std::string m_str;
};

int main()
{
	std::vector<StrWrapper> svec;
	svec.resize(1'000'000u);

	std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
	auto t_start = std::chrono::steady_clock::now();
	svec.reserve(svec.capacity() + 1);
	auto t_end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double, std::milli>{ t_end - t_start } << '\n';
}
