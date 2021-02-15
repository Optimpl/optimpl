#include "internal/list.hpp"

namespace optimpl
{
    template <class T>
    class list
    {
    public:
        ~list();

        void push_back(T);
        void prepend(T);
        size_t count(const str &);
        size_t count(char);
        size_t count(const char *);
        size_t count(int);
        void extend(list);
        void sort();
        void reverse();
        void remove();
        size_t index(T);
        T &pop();
        size_t __len__();

    private:
        T *m_Block;
        size_t m_Size;

        T &Realloc(size_t);
        void copyData(const T &, const T &, size_t, size_t, size_t, size_t);
    };
} // namespace optimpl

template <typename T>
optimpl::list<T>::~list()
{
    for (int i = 0; i < m_Size; i++)
    {
        T &obj = m_Block[i];
        delete obj;
    }
    delete[] m_Block;
    m_Size = 0;
}

template <typename T>
T &optimpl::list<T>::Realloc(size_t newSize)
{
    return new T[newSize];
}

template <typename T>
void optimpl::list<T>::copyData(const T &src, const T &dest, size_t src_starting_index, size_t src_ending_index, size_t dest_starting_index, size_t dest_ending_index)
{
    for (int i = src_starting_index, j = dest_ending_index; i <= src_ending_index && j <= dest_ending_index; i++, j++)
    {
        dest[j] = src[i];
    }
}