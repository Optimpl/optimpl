#include <optimpl/optimpl.hpp>
#include <assert.h>
#include <iostream>
#include "teststr.hpp"

#define DEBUG 1 // if this is 1, then LOG works

#if DEBUG == 1
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

void teststr()
{
    optimpl::str string = "Hello World!";

    /* reverse */
    assert(string == "Hello World!");
    string.reverse();
    assert(string == "!dlroW olleH");
    string.reverse();
    assert(string == "Hello World!");

    /* indexing */
    assert(string.at(0)=='H');
    assert(string.at(6)=='W');
    assert(string[9]=='l');
    assert(string[1]=='e');

    /* length testing */
    string += " Added string.";
    assert(optimpl::len(string)==26);
    string += optimpl::str(" This part is from optimpl::str");
    assert(optimpl::len(string)==57);

    /* concat */
    string = "";
    assert(string + "Hello" == "Hello");

    /* != */
    assert(string != "");

    /* + but it's char */
    assert(string + '!' == "!");

    /* += but it's char */
    string += ' ';              // FIXME: double free in tcache 2 when not using cin or cout (yep, like the quantum world :))
    assert(string == " ");
    
    
    freopen("tests/input.txt", "r", stdin);
    /* testing << operator */
    std::cout << string << std::endl;

    /* testing >> operator */
    optimpl::str s;
    std::cin >> s;
    std::cout << s << std::endl;
    assert(s == "Hello"); 
}
