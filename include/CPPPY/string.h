/* -------------------------------------------------------------------------- */
/*                     IMPLEMENTS THE STR CLASS OF PYTHON                     */
/* -------------------------------------------------------------------------- */

/*

This file implements the python str class inside "cpppy" namespace. It
uses standard c++ string to implement this. It is also possible to use
the class without using the cpppy namespace.

*/

#include <string> // std::string
#include <stdexcept> // for throwing exceptions to ruin lives
#include <stdlib.h> // memory allocation
#include <string.h> // strcpy
#include <type_traits> // template

namespace cpppy {
    class str;
}

class str {
    private:
        std::string string;

        char get(int idx) {
            if(idx >= string.size()) {
                throw std::out_of_range("String index out of range!");
            } else {
                return string[idx];
            }
        }

    public:
        // For std::string
        str(std::string inputString = "") {
            string = inputString;
        }

        // For char
        str(const char* inputString) {
            string = inputString;
        }

        char operator[](int idx) {
            return get(idx);
        }

        str operator+(std::string right) {
            return str(string + right);
        }

        str operator+(str right) {
            return str(string + right.get());
        }

        str& operator+=(const std::string right) {
            this -> string += right;
            return *this;
        }

        str& operator+=(str const right) {
            this ->  string += right.get();
            return *this;
        }

        operator char*() {
            // I know, you know, this code results in a memory leak. But I don't know how to fix. Make a PR(Pull Request) if you are genius enough to solve this problem.
            
            // Allocate memory for result charecter array
            char *result = (char *)malloc(sizeof(char) * string.size());

            for(int i = 0; i < string.size(); i++) {
                result[i] = string[i];
            }

            return result;

            // It's never gonna get executed. Just for my mental peace
            free(result);
        }

        operator std::string() {
            return string;
        }

        std::string get() {
            return string;
        }

        std::string get() const {
            return string;
        }

        int length() {
            return string.size();
        }
};