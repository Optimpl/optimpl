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

        char &at(unsigned int) const;
        void reverse();
        const char *c_str() const;
        void capitalize();
        str &concat(const char *);
        // list split(const char*);

        unsigned int __len__() const;

        char &operator[](unsigned int) const;
        str &operator+=(const char *);
        str &operator+=(const str &);
        str &operator+(const char *);
        str &operator+(const str &);
        str &operator*(unsigned int);
        bool operator==(const char *) const;
        bool operator==(const str &) const;
    };
} // namespace optimpl

optimpl::str::str(const char *source)
{
    size = strlen(source);
    c_string = new char[size + 1];
    memcpy(c_string, source, size);
    c_string[size] = '\0';
}

optimpl::str::str(const str &source)
    : size(source.size)
{
    c_string = new char[size];
    memcpy(c_string, source.c_string, size);
    c_string[size] = '\0';
}

optimpl::str::~str()
{
    delete[] c_string;
}

char &optimpl::str::at(unsigned int idx) const
{
    if (idx < 0 || idx > size - 1)
    {
        throw "OutOfRangeException: Index is out of range";
    }
    return c_string[idx];
}

void optimpl::str::reverse()
{
    for (unsigned int i = 0, j = size - 1; i < (size / 2); i++, j--)
    {
        char temp = c_string[i];
        c_string[i] = c_string[j];
        c_string[j] = temp;
    }
}

/*
    This function returns pointer to the core c_string variable which contains the string.
    Editing that may cause problems.
*/
const char *optimpl::str::c_str() const
{
    return c_string;
}

void optimpl::str::capitalize()
{
    bool isspace = false;
    for (unsigned int i = 0; i < size; i++)
    {
        if (c_string[i] == ' ')
        {
            isspace = true;
        }
        else if (isspace)
        {
            c_string[i] = toupper(c_string[i]);
            isspace = false;
        }
        else
        {
            c_string[i] = tolower(c_string[i]);
        }
    }
}

optimpl::str &optimpl::str::concat(const char *rval)
{
    int totalSize = size + strlen(rval) + 1;
    int currentSize = size;
    char *result = new char[totalSize];
    memcpy(result, c_string, size);

    for (int j = currentSize; j < totalSize; j++)
    {
        result[j] = rval[abs(currentSize - j)];
    }
    result[totalSize] = '\0';

    delete [] c_string;
    c_string = result;
    size = totalSize;
    return *this;
}

unsigned int optimpl::str::__len__() const
{
    return size;
}

char &optimpl::str::operator[](unsigned int idx) const
{
    return at(idx);
}

optimpl::str &optimpl::str::operator+=(const char *rval)
{
    concat(rval);
    return *this;
}

optimpl::str &optimpl::str::operator+=(const str &rval)
{
    concat(rval.c_str());
    return *this;
}

bool optimpl::str::operator==(const char *rval) const
{
    return strcmp(c_string, rval) == 0;
}

bool optimpl::str::operator==(const str &rval) const
{
    return strcmp(c_string, rval.c_string) == 0;
}