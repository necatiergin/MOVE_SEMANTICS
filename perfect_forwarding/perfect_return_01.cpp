// funtion callfoo should perfectly return the return value of foo  
// what should be the return type of call_foo?

template<typename T>
??? call_foo(T&& arg)
{
    return foo(std::forward<T>(arg));
}
