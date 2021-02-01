#include <optimpl/optimpl.hpp>
#include <assert.h>
#include <iostream>
#include "teststr.hpp"

#define LOG(N) std::cout<<N<<std::endl;

void teststr()
{
    optimpl::str s = "Test String";
    assert(s == "Test String");
    // assert(s == std::string("Test String"));
    assert((s + " Addition") == "Test String Addition");
    assert(optimpl::len(s + " Addition") == 20);
    // assert((s + std::string(" Addition")) == std::string("Test String Addition"));
    // assert(len(s + std::string(" Addition"))== 20);
    s += " Permanent Addition";
    assert(s == "Test String Permanent Addition");
    assert(optimpl::len(s)==30);
    // s += std::string(" std::string()");
    // assert(s == "Test String Permanent Addition std::string()");
    // assert(optimple::len(s)==44);
}