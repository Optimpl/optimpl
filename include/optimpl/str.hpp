
#include <string>
#include <string.h>
#include <optimpl/logr.hpp>

namespace optimpl
{
    class str
    {
    private:
        char *c_string;
        long unsigned int string_length;

    public:
        str(const char *source);
        str(std::string);
        ~str();
        void captialize();
        int __len__();
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

optimpl::str::~str()
{
    free(this->c_string);
}

int optimpl::str::__len__()
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

    char newStr[this->string_length + rvalLength + 1];

    for (unsigned long int i = 0; i < this->string_length; i++)
    {
        newStr[i] = this->c_string[i];
    }
    for (unsigned long int i = this->string_length, j = 0; i < this->string_length + rvalLength; i++, j++)
    {
        newStr[i] = rval[j];
    }
    newStr[(this->string_length + rvalLength)] = '\0';

    this->string_length = rvalLength + this->string_length;
    free(this->c_string);
    this->c_string = (char *)malloc(sizeof(char) * (this->string_length + rvalLength));
    memcpy(this->c_string, newStr, (this->string_length + rvalLength));
}

void optimpl::str::operator+=(const char *rval)
{
    int rvalLength;
    for (rvalLength = 0; rval[rvalLength] != '\0'; rvalLength++)
        ;

    char newStr[this->string_length + rvalLength + 1];

    for (unsigned long int i = 0; i < this->string_length; i++)
    {
        newStr[i] = this->c_string[i];
    }
    for (unsigned long int i = this->string_length, j = 0; i < this->string_length + rvalLength; i++, j++)
    {
        newStr[i] = rval[j];
    }
    newStr[(this->string_length + rvalLength)] = '\0';

    this->string_length = rvalLength + this->string_length;
    free(this->c_string);
    this->c_string = (char *)malloc(sizeof(char) * (this->string_length + rvalLength));
    memcpy(this->c_string, newStr, (this->string_length + rvalLength));
}

bool optimpl::str::operator==(std::string rval)
{
    return strcmp(rval.c_str(), this->c_string) == 0;
}

bool optimpl::str::operator==(const char *rval)
{
    return strcmp(rval, this->c_string) == 0;
}