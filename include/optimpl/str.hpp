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
    this->size = strlen(source);
    this->c_string = new char[this->size + 1];
    memcpy(c_string, source, this->size);
    this->c_string[this->size] = '\0';
}

optimpl::str::str(const str &source)
    : size(source.size)
{
    this->c_string = new char[this->size];
    memcpy(this->c_string, source.c_string, this->size);
    this->c_string[this->size] = '\0';
}

optimpl::str::~str()
{
    delete[] this->c_string;
}

char &optimpl::str::at(unsigned int idx) const
{
    if (idx < 0 || idx > this->size - 1)
    {
        throw "OutOfRangeException: Index is out of range";
    }
    return this->c_string[idx];
}

void optimpl::str::reverse()
{
    for (unsigned int i = 0, j = this->size - 1; i < (this->size / 2); i++, j--)
    {
        char temp = this->c_string[i];
        this->c_string[i] = this->c_string[j];
        this->c_string[j] = temp;
    }
}

/*
    This function returns pointer to the core c_string variable which contains the string.
    Editing that may cause problems.
*/
const char *optimpl::str::c_str() const
{
    return this->c_string;
}

void optimpl::str::capitalize()
{
    bool isspace = false;
    for (unsigned int i = 0; i < this->size; i++)
    {
        if (this->c_string[i] == ' ')
        {
            isspace = true;
        }
        else if (isspace)
        {
            this->c_string[i] = toupper(this->c_string[i]);
            isspace = false;
        }
        else
        {
            this->c_string[i] = tolower(this->c_string[i]);
        }
    }
}

optimpl::str &optimpl::str::concat(const char *rval)
{
    int totalSize = this->size + strlen(rval) + 1;
    int currentSize = this->size;
    char *result = new char[totalSize];
    memcpy(result, this->c_string, this->size);

    for (int j = currentSize; j < totalSize; j++)
    {
        result[j] = rval[abs(currentSize - j)];
    }
    result[totalSize] = '\0';

    delete [] this->c_string;
    this->c_string = result;
    this->size = totalSize;
    return *this;
}

unsigned int optimpl::str::__len__() const
{
    return this->size;
}

char &optimpl::str::operator[](unsigned int idx) const
{
    return this->at(idx);
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
    return strcmp(this->c_string, rval) == 0;
}

bool optimpl::str::operator==(const str &rval) const
{
    return strcmp(this->c_string, rval.c_string) == 0;
}