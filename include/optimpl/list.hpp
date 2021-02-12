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
        T pop();
        size_t __len__();

    private:
        T *block;
        size_t size;

        void Realloc(size_t);
        void copyData(size_t, size_t, T *);
    };
} // namespace optimpl