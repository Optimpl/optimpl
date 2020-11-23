/* -------------------------------------------------------------------------- */
/*                         IMPLEMENTS PYTHON INT CLASS                        */
/* -------------------------------------------------------------------------- */
/*
This file implements the int class of python. Uses int array to store int
*/

#include<string> // std::string
#include<cstdint> // SIZE_MAX
#include<stdexcept> // exceptions
#include "./string.h" // To concat error message


namespace PYICPP {
    class Int; //Because int is a statement
}

class Int {
    private:
        int *num;
    
    public:
        Int(std::string number) {
            int len = number.size();
            num = new int[len];

            for(int i = 0; i < len; i++) {
                switch(number[i]) {
                    case '1':
                        num[i] = 1;
                        break;
                    case '2':
                        num[i] = 2;
                        break;
                    case '3':
                        num[i] = 3;
                        break;
                    case '4':
                        num[i] = 4;
                        break;
                    case '5':
                        num[i] = 5;
                        break;
                    case '6':
                        num[i] = 6;
                        break;
                    case '7':
                        num[i] = 7;
                        break;
                    case '8':
                        num[i] = 8;
                        break;
                    case '9':
                        num[i] = 9;
                        break;
                    case '0':
                        num[i] = 0;
                        break;
                    default:
                        throw std::invalid_argument(str("Invalid charecter '")+str((char*)number[i])+str("'!"));
                        break;
                }
            }
        }
        Int(int number) {
            num = (int*)number;
        }
        Int(str number) {
            int len = number.length();
            num = new int[len];

            for(int i = 0; i < len; i++) {
                switch(number[i]) {
                    case '1':
                        num[i] = 1;
                        break;
                    case '2':
                        num[i] = 2;
                        break;
                    case '3':
                        num[i] = 3;
                        break;
                    case '4':
                        num[i] = 4;
                        break;
                    case '5':
                        num[i] = 5;
                        break;
                    case '6':
                        num[i] = 6;
                        break;
                    case '7':
                        num[i] = 7;
                        break;
                    case '8':
                        num[i] = 8;
                        break;
                    case '9':
                        num[i] = 9;
                        break;
                    case '0':
                        num[i] = 0;
                        break;
                    default:
                        const char invalid_char = number[i];
                        throw std::invalid_argument("Invalid charecter: "+invalid_char);
                        break;
                }
            }
        }
        operator int*() {
            return num;
        }
        int getIntArray() {
            return (int)num;
        }
        Int operator*(Int right) {
            return *num * right.getIntArray();
        }
        Int operator+(Int right) {
            return *num + right.getIntArray();
        }
        Int operator/(Int right) {
            return *num / right.getIntArray();
        }
};