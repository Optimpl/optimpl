#include <PYICPP/string.hpp>
#include <iostream>
using namespace PYICPP;

int main()
{
  str s = "Hello World!";
  std::cout << "Assign: " << s << std::endl;
  s = s + " Hello";
  std::cout << "+ operator " << s << std::endl;
  std::cout << "isAlpha() " << s.isalpha() << std::endl;
  std::cout << "capitalize() " << s.capitalize() << std::endl;
  std::cout << "len() " << s.len() << std::endl;
  std::cout << "count() " << s.count("He") << std::endl;
}