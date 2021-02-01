#include<optimpl/optimpl.hpp>
#include<assert.h>
#include<string>
#include<iostream>
#include "teststr.hpp"

void teststr() {
    optimpl::str s = "Test String";
    assert(s=="Test String");
    assert(s==std::string("Test String"));
    assert((s+" Addition") == "Test String Addition");
    assert((s+std::string(" Addition")) == std::string("Test String Addition"));
    s += " Permanent Addition";
    assert(s=="Test String Permanent Addition");
    s += std::string(" std::string()");
    assert(s=="Test String Permanent Addition std::string()");
}