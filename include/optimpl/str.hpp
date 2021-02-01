
#include <string>
#include <string.h>
#include "internal/logr.hpp"

namespace optimpl
{
    class str
    {
    private:
        char *c_string = nullptr;
        long unsigned int string_length;
        void freeit();

    public:
        str(const char *source);
        str(std::string);
        str();
        ~str();
        void captialize();
        int len();
        operator const char *();
        optimpl::str operator+(std::string);
        optimpl::str operator+(const char *);
        void operator+=(std::string);
        void operator+=(const char *);
        bool operator==(std::string);
        bool operator==(const char *);
    };
} // namespace optimpl

optimpl::str::str(const char *source)
{
    int len;
    for (len = 0; source[len] != '\0'; len++)
        ;

    this->string_length = len;
    this->c_string = (char *)malloc(sizeof(char) * this->string_length);
    memcpy(this->c_string, source, this->string_length);
}

optimpl::str::str(std::string source)
{
    this->string_length = source.length();
    this->c_string = (char *)malloc(sizeof(char) * this->string_length);
    memcpy(this->c_string, source.c_str(), this->string_length);
}

optimpl::str::str() {
    this->c_string = (char *)malloc(0);
    this->string_length = 0;
}

optimpl::str::~str()
{
    freeit();
}

void optimpl::str::freeit() {
    if(this->string_length == 0 || !this->c_string) {
        return;
    }
    delete[] this->c_string;
    this->c_string = nullptr;
    this->string_length = 0;
}

int optimpl::str::len()
{
    return this->string_length;
}

optimpl::str::operator const char *()
{
    return this->c_string;
}

optimpl::str optimpl::str::operator+(std::string rval)
{
    int rvalLength = rval.length();

    char newStr[(this->string_length + rvalLength) + 1];
    for (unsigned long int i = 0; i < this->string_length; i++)
    {
        newStr[i] = this->c_string[i];
    }
    for (unsigned long int i = this->string_length, j = 0; i < this->string_length + rvalLength; i++, j++)
    {
        newStr[i] = rval[j];
    }
    newStr[(this->string_length + rvalLength)] = '\0';
    return *(new optimpl::str(newStr));
}

optimpl::str optimpl::str::operator+(const char *rval)
{
    int rvalLength;
    for (rvalLength = 0; rval[rvalLength] != '\0'; rvalLength++)
        ;

    char newStr[(this->string_length + rvalLength) + 1];
    for (unsigned long int i = 0; i < this->string_length; i++)
    {
        newStr[i] = this->c_string[i];
    }
    for (unsigned long int i = this->string_length, j = 0; i < this->string_length + rvalLength; i++, j++)
    {
        newStr[i] = rval[j];
    }
    newStr[(this->string_length + rvalLength)] = '\0';
    return *(new optimpl::str(newStr));
}

void optimpl::str::operator+=(std::string rval)
{
    int rvalLength = rval.length();
    unsigned long int totalLength = this->string_length + rvalLength;

    char newStr[totalLength + 1];

    for (unsigned long int i = 0; i < this->string_length; i++)
    {
        newStr[i] = this->c_string[i];
    }
    for (unsigned long int i = this->string_length, j = 0; i < totalLength; i++, j++)
    {
        newStr[i] = rval[j];
    }
    newStr[totalLength] = '\0';

    freeit();
    this->string_length = totalLength;
    this->c_string = (char *)malloc(sizeof(char) * totalLength);
    memcpy(this->c_string, newStr, totalLength);
}

void optimpl::str::operator+=(const char *rval)
{
    int rvalLength;
    for (rvalLength = 0; rval[rvalLength] != '\0'; rvalLength++)
        ;
    unsigned long int totalLength = this->string_length + rvalLength;

    char newStr[totalLength + 1];

    for (unsigned long int i = 0; i < this->string_length; i++)
    {
        newStr[i] = this->c_string[i];
    }
    for (unsigned long int i = this->string_length, j = 0; i < totalLength; i++, j++)
    {
        newStr[i] = rval[j];
    }
    newStr[totalLength] = '\0';

    freeit();
    this->string_length = totalLength;
    this->c_string = (char *)malloc(sizeof(char) * totalLength);
    memcpy(this->c_string, newStr, totalLength);
}

bool optimpl::str::operator==(std::string rval)
{
    return strcmp(rval.c_str(), this->c_string) == 0;
}

bool optimpl::str::operator==(const char *rval)
{
    return strcmp(rval, this->c_string) == 0;
}