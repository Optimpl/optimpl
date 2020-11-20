#include<iostream>
#include "../include/PYICPP/string.h"


int main() {
    str test = "Hello world!";

    //Conversion to char*
    std::cout<<"Conversion to char*: "<<test<<std::endl;

    //Concatenation
    // With std::string
    std::string concatstd = " nice to meet y'all";

    test = test + concatstd;

    std::cout<<"Concatenation with std::string with operator '=': "<<test<<std::endl;

    // With str
    str concatstr = " nice to meet y'all(py)";

    test = "Hello World";

    test = test + concatstr;

    std::cout<<"Concatenation with PYICPP::str with operator '=': "<<test<<std::endl;

    // Using +=
    // With str

    test = "Hello World";

    test += concatstr;

    std::cout<<"Concatenation with PYICPP::str with operator '+=': "<<test<<std::endl;

    // With std::string 

    test = "Hello World";

    test += concatstd;

    std::cout<<"Concatenation with std::string with operator '+=': "<<test<<std::endl;

    // Getting length

    test = "Hello World";

    std::cout<<"Length should be 11 and the length method returns: "<<test.length()<<std::endl;

    // Using operator [] to access elements
    // This should return 'H'

    test = "Hello World";

    std::cout<<"The class should give us 'H' and it gives: "<<test[0]<<std::endl;

    // This should throw exception

    test = "Hello World";

    std::cout<<"Exception expected ¯\\_(ツ)_/¯"<<test[-1]<<std::endl;

}