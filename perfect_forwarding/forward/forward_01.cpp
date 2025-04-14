// <utility> içinde tanımlıdır
namespace std {

    template <typename T>
    constexpr T&& forward(std::remove_reference_t<T>& t) noexcept {
        return static_cast<T&&>(t);
    }

    template <typename T>
    constexpr T&& forward(std::remove_reference_t<T>&& t) noexcept {
        static_assert(!std::is_lvalue_reference<T>::value,
                      "bad forward call");
        return static_cast<T&&>(t);
    }

}
