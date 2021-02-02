#include <iostream>
#include "internal/logr.hpp"
#include "internal/str.hpp"

namespace optimpl
{
    class str
    {

    private:
        char *c_string;
        unsigned int size;

    public:
        str(const char *);
        str(const str &);
        ~str();

        char &at(unsigned int);
        void reverse();
        char *c_str();
        void capitalize();
        // list split(const char*);

        unsigned int __len__();

        char &operator[](unsigned int);
        str &operator+=(const char *);
        str &operator+=(const str &);
        str &operator+(const char *);
        str &operator+(const str &);
        str &operator*(unsigned int);

        friend std::ostream &operator<<(std::ostream &, const str &);
    };
} // namespace optimpl