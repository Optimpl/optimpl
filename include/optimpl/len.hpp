namespace optimpl
{
    size_t len(optimpl::str);
    template <typename T>
    size_t len(optimpl::list<T> target);
} // namespace optimpl
size_t optimpl::len(optimpl::str target)
{
    return target.__len__();
}
template <typename T>
size_t optimpl::len(optimpl::list<T> target)
{
    return target.__len__();
}