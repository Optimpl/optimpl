#include "internal/logr.hpp"
#include "internal/str.hpp"

namespace optimpl
{
    class str
    {
    private:
        char *c_string = nullptr;
        void freeit();

    public:
        str(const char *source);
        str();
        str(const str&);
        ~str();
        int __len__();
        operator const char *();
        optimpl::str operator+(const char *);
        void operator+=(const char *);
        bool operator==(const char *);
    };
} // namespace optimpl

optimpl::str::str(const char *source)
{
    int len = strlen(source);
    this->c_string = new char[len+1];
    memmove(this->c_string, source, len);
    this->c_string[len] = '\0';
}
optimpl::str::str()
{
    this->c_string = new char[0];
}
optimpl::str::str(const optimpl::str &str) {
    this->c_string = str.c_string;
}
optimpl::str::~str()
{
    delete[] this->c_string;
}
int optimpl::str::__len__()
{
    return strlen(this->c_string);
}
optimpl::str::operator const char *()
{
    return this->c_string;
}
optimpl::str optimpl::str::operator+(const char *rval) {
    int rvalLength = strlen(rval);
    int currentLength = strlen(this->c_string);
    int totalLength = rvalLength + currentLength;
    char* resultString = new char[totalLength + 1];

    for(int i = 0; i < currentLength; i++) {
        resultString[i] = this->c_string[i];
    }
    for(int j = currentLength; j < totalLength; j++) {
        resultString[j] = rval[abs(currentLength-j)];
    }
    resultString[totalLength + 1] = '\0';
    optimpl::str result = resultString;
    return result;
}
void optimpl::str::operator+=(const char *rval) {
    int rvalLength = strlen(rval);
    int currentLength = strlen(this->c_string);
    int totalLength = rvalLength + currentLength;
    char* resultString = new char[totalLength + 1];

    for(int i = 0; i < currentLength; i++) {
        resultString[i] = this->c_string[i];
    }
    for(int j = currentLength; j < totalLength; j++) {
        resultString[j] = rval[abs(currentLength-j)];
    }
    resultString[totalLength + 1] = '\0';
    this->c_string = resultString;
}
bool optimpl::str::operator==(const char *rval)
{
    return strcmp(this->c_string, rval) == 0;
}