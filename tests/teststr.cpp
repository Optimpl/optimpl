#include <optimpl/optimpl.hpp>
#include <assert.h>
#include <iostream>
#include "teststr.hpp"

#define LOG(N) std::cout<<N<<std::endl;

void teststr()
{
    optimpl::str string = "Hello World!";
    assert(string == "Hello World!");
    string.reverse();
}