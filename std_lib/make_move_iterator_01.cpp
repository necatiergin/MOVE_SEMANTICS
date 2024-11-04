template<class Iter>
constexpr std::move_iterator<Iter> make_move_iterator(Iter i)
{
    return std::move_iterator<Iter>(std::move(i));
}
