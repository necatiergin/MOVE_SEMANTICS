template<typename Func, typename... Args>
decltype(auto) call(Func f, Args&&... args)
{
    decltype(auto) ret{f(std::forward<Args>(args)...)};
    //... some code here

    if constexpr (std::is_rvalue_reference_v<decltype(ret)>) {
        return std::move(ret); // move xvalue returned by f() to the caller
    }
    else {
        return ret; // return the plain value or the lvalue reference
    }
}
