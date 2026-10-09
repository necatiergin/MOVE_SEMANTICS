#include <type_traits>

using A = std::add_lvalue_reference_t<int&&>;  // int&
using B = std::add_rvalue_reference_t<int&>;   // int&
using C = std::add_rvalue_reference_t<int&&>;  // int&&
