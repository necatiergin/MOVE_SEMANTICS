#include <utility>
#include <memory>


template<class T, class... A>
std::unique_ptr<T> makeUnique(A&&... args)
{
    return unique_ptr<T>(new T(std::forward<A>(args)...));
}
