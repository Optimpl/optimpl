#include <iostream>
#include <cstring>

class GanjaStr {
private:
    char* m_String; // our main string
    unsigned int m_Size; // and that's the size of it
public:
    // constructor
    GanjaStr(const char* s) 
    {
        m_Size = strlen(s);
        m_String = new char[m_Size+1];
        memcpy(m_String, s, m_Size);
        m_String[m_Size] = '\0';
    }

    // copy constructor
    GanjaStr(const GanjaStr& another_string)
        : m_Size(another_string.m_Size)
    {
        m_String = new char[m_Size + 1];
        memcpy(m_String, another_string.m_String, m_Size+1);
    }

    // destructor
    ~GanjaStr()
    {
        delete[] m_String;
    }

    // indexing operator
    char& operator[](unsigned int index)
    {
        return m_String[index];
    }
    
    // just like C++ strings has .at(), it works same as indexing operator []
    char& at(unsigned int index)
    {
        return m_String[index];
    }

    // a method that can reverse the string
    void reverse()
    {
        for(int i = 0, j = m_Size-1; i < (m_Size/2); i++, j--) {
            char temp = m_String[i];
            m_String[i] = m_String[j];
            m_String[j] = temp;
        }
    }

    // a method that returns the size of the string
    unsigned int size()
    {
        return m_Size;
    }

    // this operator helps us to print GanjaStr type by using cout 
    friend std::ostream& operator<<(std::ostream& stream, const GanjaStr& string);
};

// implementation of the operator that helps us to print GanjaStr type by using cout
std::ostream& operator<<(std::ostream& stream, const GanjaStr& string)
{
    stream << string.m_String;
    return stream;
}

// a function that will help us
void debug(GanjaStr& a, GanjaStr& b)
{
    std::cout << "----START----\n";
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "----END----\n\n";
}

// our main function for checking GanjaStr
int main()
{
    GanjaStr a = "shanto";
    GanjaStr b = a;

    b[0] = 'a';
    debug(a, b);
    
    a.at(0) = 'a';
    debug(a, b);

    a.reverse();
    b.reverse();
    debug(a, b);

    std::cout << "Size of a: " << a.size() << '\n';
    std::cout << "Size of b: " << b.size() << '\n';
}
