#include <utility>

int x{};
const int cx{};

auto&& r1 = x;   // int&
auto&& r2 = 10;  // int&&
auto&& r3 = cx;   // const int&
auto&& r4 = std::move(cx);   // const int&&
