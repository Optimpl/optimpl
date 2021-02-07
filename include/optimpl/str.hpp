#include <iostream>
#include "internal/logr.hpp"
#include "internal/str.hpp"

namespace optimpl
{
    class str
    {

    private:
        char *m_Buffer;
        unsigned int m_Size = 0;

        char *empty_string();
        char *concat(const char *);

    public:
        str(const char *);
        str(const str &);
        ~str();

        char &at(unsigned int) const;
        void reverse();
        const char *c_str() const;
        void capitalize();
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
    if (*(source) == '\0')
    {
        m_Size = 0;
        m_Buffer = empty_string();
        return;
    }
    m_Size = strlen(source);
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, source, m_Size);
    m_Buffer[m_Size] = '\0';
}

optimpl::str::str(const str &source)
    : m_Size(source.m_Size)
{
    if (*(source.c_str()) == '\0')
    {
        m_Size = 0;
        m_Buffer = empty_string();
        return;
    }
    m_Buffer = new char[m_Size];
    memcpy(m_Buffer, source.m_Buffer, m_Size);
    m_Buffer[m_Size] = '\0';
}

optimpl::str::~str()
{
    delete[] m_Buffer;
}

char *optimpl::str::empty_string()
{
    return new char('\0');
}

char &optimpl::str::at(unsigned int idx) const
{
    if (idx < 0 || idx > m_Size - 1)
    {
        throw "OutOfRangeException: Index is out of range";
    }
    return m_Buffer[idx];
}

void optimpl::str::reverse()
{
    for (unsigned int i = 0, j = m_Size - 1; i < (m_Size / 2); i++, j--)
    {
        char temp = m_Buffer[i];
        m_Buffer[i] = m_Buffer[j];
        m_Buffer[j] = temp;
    }
}

/*
    This function returns pointer to the core m_Buffer variable which contains the string.
    Editing that may cause problems.
*/
const char *optimpl::str::c_str() const
{
    return m_Buffer;
}

void optimpl::str::capitalize()
{
    bool isspace = false;
    for (unsigned int i = 0; i < m_Size; i++)
    {
        if (m_Buffer[i] == ' ')
        {
            isspace = true;
        }
        else if (isspace)
        {
            m_Buffer[i] = toupper(m_Buffer[i]);
            isspace = false;
        }
        else
        {
            m_Buffer[i] = tolower(m_Buffer[i]);
        }
    }
}

char *optimpl::str::concat(const char *rval)
{
    int totalSize = m_Size + strlen(rval) + 1;
    int currentSize = m_Size;
    char *result = new char[totalSize];
    memcpy(result, m_Buffer, m_Size);

    for (int j = currentSize; j < totalSize; j++)
    {
        result[j] = rval[abs(currentSize - j)];
    }
    result[totalSize] = '\0';

    return result;
}

unsigned int optimpl::str::__len__() const
{
    return m_Size;
}

char &optimpl::str::operator[](unsigned int idx) const
{
    return at(idx);
}

optimpl::str &optimpl::str::operator+=(const char *rval)
{
    char *result = concat(rval);
    delete[] m_Buffer;
    m_Buffer = new char[strlen(result) + 1];
    m_Size = strlen(result);
    memcpy(m_Buffer, result, m_Size);
    m_Buffer[m_Size + 1] = '\0';
    return *this;
}

optimpl::str &optimpl::str::operator+=(const str &rval)
{
    char *result = concat(rval.c_str());
    delete[] m_Buffer;
    m_Buffer = new char[strlen(result) + 1];
    m_Size = strlen(result);
    memcpy(m_Buffer, result, m_Size);
    m_Buffer[m_Size + 1] = '\0';
    return *this;
}

optimpl::str &optimpl::str::operator+(const char *rval)
{
    return *(new str(concat(rval)));
}

optimpl::str &optimpl::str::operator+(const str &rval)
{
    return *(new str(concat(rval.c_str())));
}

bool optimpl::str::operator==(const char *rval) const
{
    return strcmp(m_Buffer, rval) == 0;
}

bool optimpl::str::operator==(const str &rval) const
{
    return strcmp(m_Buffer, rval.m_Buffer) == 0;
}

std::ostream& operator<<(std::ostream &stream, const optimpl::str &string)
{
    stream << string.c_str();
    return stream;
}
