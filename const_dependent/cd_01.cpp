template<typename T>
void foo(T&& arg)
{
  if constexpr(std::is_const_v<std::remove_reference_t<T>>) {
      //passed argument is const
  }
  else {
    // passed argument is not const
  }
}
