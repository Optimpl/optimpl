#include <optimpl/optimpl.hpp>
#include <assert.h>
#include <iostream>
#include "teststr.hpp"

#define LOG(N) std::cout<<N<<std::endl;

void teststr()
{
    optimpl::str s = "Test String";
    assert(s == "Test String");
    assert(s == std::string("Test String"));
    assert((s + " Addition") == "Test String Addition");
    assert((s + " Addition").len() == 20);
    assert((s + std::string(" Addition")) == std::string("Test String Addition"));
    assert((s + std::string(" Addition")).len() == 20);
    s += " Permanent Addition";
    assert(s == "Test String Permanent Addition");
    assert(s.len()==30);
    s += std::string(" std::string()");
    assert(s == "Test String Permanent Addition std::string()");
    assert(s.len()==44);
}