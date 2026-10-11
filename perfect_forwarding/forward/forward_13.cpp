// CONSUME OR OBSERVE PATERNİ


#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

template <typename T>
void consume_or_observe(T&& arg)
{
    if constexpr (std::is_lvalue_reference_v<T>) {
        std::cout << "Observing: " << arg << '\n';
    }
    else {
        std::string owned = std::forward<T>(arg);

        std::cout << "Consuming: " << owned << '\n';
    }
}

int main()
{
    std::string s{"necati"};

    consume_or_observe(s);             // observe
    consume_or_observe(std::move(s));  // consume
}
